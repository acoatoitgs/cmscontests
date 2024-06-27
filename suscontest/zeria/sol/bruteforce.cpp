// @check-accepted: esempi N_20 N_1000000
// @check-zero: full
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    long long N;
    cin >> N;

    int count = 0;
    for (int i = 5; i <= N; i++)
    {
        int k = i;
        while (k % 5 == 0)
        {
            count++;
            k /= 5;
        }
    }

    cout << count << "\n";
}
