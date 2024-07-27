// @check-accepted: example N_le_11 full
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
#pragma GCC optimize("Ofast")

vector<int> squares;
vector<pair<int, int>> memo;

int main()
{

    int N;
    cin >> N;
    for (int i = 1; i <= sqrt(1'000'000); i++)
    {
        squares.push_back(i * i);
    }
    memo.resize(N + 1, {-1, -1});
    memo[0] = {-1, 0};
    for (int i = 1; i <= N; i++)
    {
        int k = 0;
        pair<int, int> best = {-1, 100000};
        while (squares[k] <= i)
        {
            if (memo[i - squares[k]].second < best.second)
            {
                best.second = memo[i - squares[k]].second + 1;
                best.first = squares[k];
            }
            k++;
        }
        memo[i] = best;
    }

    vector<int> ans;
    pair<int, int> sol = memo[N];
    int C = N;
    while (sol.first != -1)
    {
        ans.push_back(sqrt(sol.first));
        C -= sol.first;
        sol = memo[C];
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (auto i : ans)
        cout << i << " ";
    cout << "\n";
    return 0;
}
