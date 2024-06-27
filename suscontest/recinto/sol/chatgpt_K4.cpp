// @check-wrong-answer: esempi N_30.K_30 N_30 K_30
// @check-zero: full
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Funzione per contare le combinazioni valide
long long count_valid_combinations(const vector<int> &arr, int K)
{
    int N = arr.size();
    long long count = 0;

    // Mappa per memorizzare la frequenza dei resti dei numeri rispetto a K
    unordered_map<int, int> remainder_count;

    // Conteggio dei resti e gestione dei numeri negativi
    for (int i = 0; i < N; ++i)
    {
        int remainder = arr[i] % K;
        if (remainder < 0)
        {
            remainder += K; // Garantisce che remainder sia positivo
        }
        remainder_count[remainder]++;
    }

    // Iterazione su tutte le combinazioni possibili di 4 resti
    for (auto it1 = remainder_count.begin(); it1 != remainder_count.end(); ++it1)
    {
        int remainder1 = it1->first;
        int count1 = it1->second;

        for (auto it2 = it1; it2 != remainder_count.end(); ++it2)
        {
            int remainder2 = it2->first;
            int count2 = it2->second;

            for (auto it3 = it2; it3 != remainder_count.end(); ++it3)
            {
                int remainder3 = it3->first;
                int count3 = it3->second;

                for (auto it4 = it3; it4 != remainder_count.end(); ++it4)
                {
                    int remainder4 = it4->first;
                    int count4 = it4->second;

                    // Verifica se la somma dei 4 resti è un multiplo di K
                    if ((remainder1 + remainder2 + remainder3 + remainder4) % K == 0)
                    {
                        // Calcolo delle combinazioni valide
                        if (it1 == it2 && it2 == it3 && it3 == it4)
                        {
                            // Tutti uguali
                            count += (1LL * count1 * (count1 - 1) * (count1 - 2) * (count1 - 3)) / 24;
                        }
                        else if (it1 == it2 && it2 == it3)
                        {
                            // Tre uguali, uno diverso
                            count += (1LL * count1 * (count1 - 1) * (count1 - 2) / 6) * count4;
                        }
                        else if (it1 == it2)
                        {
                            // Due uguali, due diversi
                            count += (1LL * count1 * (count1 - 1) / 2) * 1LL * count3 * count4;
                        }
                        else if (it3 == it4)
                        {
                            // Due uguali, due diversi
                            count += 1LL * count1 * count2 * (1LL * count3 * (count3 - 1) / 2);
                        }
                        else
                        {
                            // Tutti diversi
                            count += 1LL * count1 * count2 * count3 * count4;
                        }
                    }
                }
            }
        }
    }

    return count;
}

int main()
{
    int N, K;
    cin >> N >> K;

    vector<int> arr(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }

    long long result = count_valid_combinations(arr, K);
    cout << result << endl;

    return 0;
}
