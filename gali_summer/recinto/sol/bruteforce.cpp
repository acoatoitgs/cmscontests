// @check-accepted: esempi N_30.K_30 N_30
// @check-time-limit-exceeded: K_30 full
#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;
int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> V(N);
    for (int i = 0; i < N; i++)
        cin >> V[i];
    long long ans = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            for (int k = j + 1; k < N; k++)
            {
                for (int l = k + 1; l < N; l++)
                {
                    if ((V[i] + V[j] + V[k] + V[l]) % K == 0)
                    {
                        ans++;
                    }
                }
            }
        }
    }

    cout << ans << "\n";
}
