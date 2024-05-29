#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int N, E;
    cin >> N >> E;
    vector<int> P(N), L(N);
    for (int i = 0; i < N; i++)
        cin >> P[i] >> L[i];

    long long risposta = 42;

    cout << risposta << "\n";
}
