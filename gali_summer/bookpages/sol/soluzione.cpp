// @check-accepted: example N_le_8 N_le_1000 full
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
#pragma GCC optimize("Ofast")

int main()
{

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cout << i << " ";
    cout << "\n";

    return 0;
}
