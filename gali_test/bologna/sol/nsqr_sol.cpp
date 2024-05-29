// @check-accepted: esempi N_piccolo
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; i++)
        cin >> H[i];

    int best = 100000000;
    for (int i = 0; i < N; i++)
    {
        for (int k = i; k < N; k++)
        {
            best = min(best, H[k]);
        }
    }
    cout << best << "\n";
}
