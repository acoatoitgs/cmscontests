// @check-accepted: example N_le_11 full
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
#pragma GCC optimize("Ofast")

vector<int> squares;
vector<vector<int>> memo;

vector<int> dp(int n)
{
    if (n == 0)
        return {};

    if (n < 0)
        return {1, 1, 1, 1, 1};

    if (memo[n][0] != -1)
        return memo[n];

    int i = 0;
    vector<int> best = {1, 1, 1, 1, 1}; // Lagrange theorem
    while (squares[i] <= n)
    {
        vector<int> res = dp(n - squares[i]);
        res.push_back(squares[i]);

        if (res.size() < best.size())
            best = res;
        i++;
    }
    return memo[n] = best;
}
int main()
{

    int N;
    cin >> N;
    for (int i = 1; i <= sqrt(1'000'000); i++)
    {
        squares.push_back(i * i);
    }
    memo.resize(N + 1, {-1});
    vector<int> ans = dp(N);
    sort(ans.begin(), ans.end());

    cout << ans.size() << "\n";
    for (auto e : ans)
        cout << sqrt(e) << " ";
    cout << "\n";
    return 0;
}
