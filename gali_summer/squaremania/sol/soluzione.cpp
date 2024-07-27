// @check-accepted: example N_le_1000 full
#include <iostream>
#include <math.h>
using namespace std;
#pragma GCC optimize("Ofast")

int main()
{

    int N;
    cin >> N;

    int sqr = (int)sqrt(N) * (int)sqrt(N);
    if (sqr == N)
        cout << (int)sqrt(N) << "\n";
    else
        cout << "NO\n";
    return 0;
}
