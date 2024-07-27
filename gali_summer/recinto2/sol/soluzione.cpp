// @check-accepted: esempi N_30.K_30 N_30 K_30 full
#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;
int N, K;
// ALIBABA TRIG
inline int inv(int n)
{
    return (K - (n % K)) % K;
}
unordered_map<int, int> mp;

int main()
{
    cin >> N >> K;
    vector<int> V(N);
    for (int i = 0; i < N; i++)
        cin >> V[i];
    for (int i = 0; i < N; i++)
    {
        V[i] = V[i] % K;
    }

    long long ans = 0;
    for (int i = 1; i < N - 2; i++)
    {
        for (int k = 0; k < i; k++)
        {
            mp[inv((V[k] + V[i]))]++;
        }

        for (int k = i + 2; k < N; k++)
        {
            ans += mp[(V[i + 1] + V[k]) % K];
        }
    }

    cout << ans << "\n";
}
