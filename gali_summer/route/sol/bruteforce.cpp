// @check-accepted: esempi L_2 N_le_1000 NL_le_1000000
// @check-time-limit-exceeded: full
#include <vector>
#include <iostream>
using namespace std;
int N, L;

int main()
{
    cin >> N >> L;
    vector<int> A(N), B(L);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < L; i++)
        cin >> B[i];
    long long ans = 0;

    for (int i = 0; i <= N - L; i++)
    {
        bool f = 0;
        for (int k = 0; k < L; k++)
        {
            if (A[k + i] != B[k])
            {
                f = 1;
                break;
            }
        }
        if (!f)
            ans++;
    }
    cout << ans << "\n";
}
