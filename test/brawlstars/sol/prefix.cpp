// @check-accepted: esempi A1_B10000 A1_B10000000 B10000 B10000000
// @check-runtime-error: A1 full
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int T;
    cin >> T;
    vector<long long> prefix(10000005, 0);
    for (int i = 1; i < prefix.size(); i++)
        prefix[i] = prefix[i - 1] + i;

    while (T--)
    {
        unsigned long long A, B;
        cin >> A >> B;
        cout << (prefix[B] - prefix[A - 1]) % 1000003 << " ";
    }
    cout << "\n";
}
