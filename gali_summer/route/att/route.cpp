#include <vector>
#include <iostream>
using namespace std;

int main()
{
    int N, L;
    cin >> N >> L;
    vector<int> A(N), B(L);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < L; i++)
        cin >> B[i];
    long long ans = 42;

    cout << ans << "\n";
}
