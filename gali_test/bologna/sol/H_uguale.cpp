// @check-wrong-answer: H_uguale
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

    int best = H[0];
    for (int i = 1; i < N; i++)
    {
        best = min(best, best);
        // lol
    }
    cout << best << "\n";
}
