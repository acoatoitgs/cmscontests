// @check-accepted: A1_B10000 A1_B10000000 A1
// @check-wrong-answer: esempi B10000 B10000000 full
#include <iostream>
#include <vector>
using namespace std;

unsigned long long binom(unsigned long long a)
{
    if (a == 0)
        return 0;
    return ((a * (a + 1)) >> 1);
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        unsigned long long A, B;
        cin >> A >> B;
        cout << binom(B) % 1000003 << " ";
    }
    cout << "\n";
}
