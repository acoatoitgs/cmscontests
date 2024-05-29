// @check-accepted: esempi A1_B10000 B10000
// @check-time-limit-exceeded: A1_B10000000 A1 B10000000 full
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        long long A, B;
        cin >> A >> B;
        long long risposta = 0;
        for (int i = A; i <= B; i++)
            risposta += i;

        cout << risposta % 1000003 << " ";
    }
}
