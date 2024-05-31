// @check-accepted: esempi NE_10 L_equal N_small NE_1000 full
#include <vector>
#include <iostream>
using namespace std;
using ll = long long;
int N, E;
vector<vector<ll>> memo;
vector<int> P, L;

ll dp(int pos, int en)
{
    if (en < 0)
        return -0x3f3f3f3f3f3f3f3f;
    if (pos == N)
        return 0;

    if (memo[pos][en] != -1)
        return memo[pos][en];

    return memo[pos][en] = max(dp(pos + 1, en), dp(pos + 1, en - L[pos]) + P[pos]);
}
int main()
{
    cin >> N >> E;
    P.resize(N);
    L.resize(N);
    memo.resize(N, vector<ll>(E + 1, -1));
    for (int i = 0; i < N; i++)
        cin >> P[i] >> L[i];

    cout << dp(0, E) << "\n";
}
