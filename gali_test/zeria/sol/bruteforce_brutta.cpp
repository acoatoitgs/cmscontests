// @check-accepted: esempi N_20
// @check-time-limit-exceeded: N_1000000
// @check-zero: full
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    long long N;
    cin >> N;

    long long fact = 1;
    int ans = 0;
    for (int i = 2; i <= N; i++)
        fact *= i;

    while (fact % 10 == 0)
    {
        fact /= 10;
        ans++;
    }

    cout << ans << "\n";
}
