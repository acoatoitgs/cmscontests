// @check-accepted: esempi N_30.K_30 N_30 K_30
// @check-time-limit-exceeded: full
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];
    vector<array<int, 5>> dp(k, {0, 0, 0, 0, 0});

    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        vector<array<int, 5>> buff(k, {0, 0, 0, 0, 0});
        int var = vec[i] % k;
        for (int j = 0; j < k; j++)
        {
            for (int z = 1; z < 5; z++)
                buff[(var + j) % k][z] = dp[j][z - 1];
        }
        for (int j = 0; j < k; j++)
        {
            for (int z = 0; z < 5; z++)
                dp[j][z] += buff[j][z];
        }
    }

    cout << dp[0][4] << '\n';

    return 0;
}
