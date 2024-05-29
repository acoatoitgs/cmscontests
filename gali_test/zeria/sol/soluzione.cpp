// @check-accepted: esempi N_20 N_1000000 full
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    long long N;
    cin >> N;

    long long risposta = 0;
    long long p = 5;
    while (N / p)
    {
        risposta += N / p;
        p *= 5;
    }

    cout << risposta << "\n";
}
