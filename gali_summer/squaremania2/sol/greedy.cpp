// @check-accepted: N_le_11
// @check-wrong-answer: example full

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

    vector<int> ans;

    while (N > 0)
    {
        for (int i = squares.size() - 1; i >= 0; i--)
        {
            if (squares[i] <= N)
            {
                N -= squares[i];
                ans.push_back(sqrt(squares[i]));
                break;
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (auto i : ans)
        cout << i << " ";
    cout << "\n";
    return 0;
}
