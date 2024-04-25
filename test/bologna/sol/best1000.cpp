// @check-accepted: esempi
// @check-wrong-answer: H_uguale N_piccolo N_grande
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

    int best = 1000;
    for (int i = 0; i < N; i++)
    {
        best = min(best, H[i]);
    }
    cout << best << "\n";
}
