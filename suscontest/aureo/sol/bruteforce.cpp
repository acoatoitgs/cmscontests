// @check-accepted: esempi N_100,V_i>=0 N_100
// @check-time-limit-exceeded: V_i>=0
// @check-zero: full
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define MOD 1000000007
int main()
{
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    vector<long long> st;
    long long ans = 1;
    for (int i = 0; i < N; i++)
    {
        st.push_back(A[i]);
        sort(st.begin(), st.end());
        long long f = 0;
        for (long long k = 0; k < st.size(); k++)
        {
            f += st[k] * (k + 1);
        }

        ans *= abs(f) % MOD;
        ans %= MOD;
    }

    cout << ans << "\n";
}
