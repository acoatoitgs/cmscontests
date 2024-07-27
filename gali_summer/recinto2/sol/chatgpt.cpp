// @check-wrong-answer: esempi N_30.K_30 N_30 K_30 full
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    vector<int> V(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> V[i];
    }

    map<int, int> remainder_count;
    long long total_count = 0;

    // Count pairs (i, j) and their remainders modulo K
    for (int i = 0; i < N; ++i)
    {
        for (int j = i + 1; j < N; ++j)
        {
            int sum = V[i] + V[j];
            int remainder = sum % K;
            if (remainder < 0)
            {
                remainder += K; // Ensure positive remainder
            }
            remainder_count[remainder]++;
        }
    }

    // Count quadruples (i, j, k, l) where V[i] + V[j] + V[k] + V[l] is a multiple of K
    for (int i = 0; i < N; ++i)
    {
        for (int j = i + 1; j < N; ++j)
        {
            int sum_ij = V[i] + V[j];
            int remainder_ij = sum_ij % K;
            if (remainder_ij < 0)
            {
                remainder_ij += K; // Ensure positive remainder
            }

            // Calculate the target remainder for (k, l) such that sum_kl + sum_ij is a multiple of K
            int target_remainder = (K - remainder_ij) % K;
            if (target_remainder == K)
            {
                target_remainder = 0; // Handle case when remainder_ij is 0
            }

            // Count valid (k, l) pairs
            if (remainder_count.find(target_remainder) != remainder_count.end())
            {
                total_count += remainder_count[target_remainder];

                // Exclude the case where (k, l) are from the same pair (i, j)
                if (target_remainder == remainder_ij)
                {
                    total_count--;
                }
            }
        }
    }

    cout << total_count << endl;

    return 0;
}
