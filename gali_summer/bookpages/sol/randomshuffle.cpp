// @check-wrong-answer: example N_le_8 N_le_1000 full
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
#pragma GCC optimize("Ofast")

int main()
{

    int N;
    cin >> N;

    vector<int> ans(N);
    iota(ans.begin(), ans.end(), 1);
    random_shuffle(ans.begin(), ans.end());

    for (auto i : ans)
        cout << i << " ";
    cout << "\n";
    return 0;
}
