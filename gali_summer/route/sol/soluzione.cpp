// @check-accepted: esempi L_2 N_le_1000 NL_le_1000000 full
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    int N, L;
    cin >> N >> L;
    vector<int> Z(N + L + 1, 0);
    vector<int> A(N), arr(L);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    for (int i = 0; i < L; i++)
        cin >> arr[i];
    arr.push_back(1000000000);
    for (int i = 0; i < N; i++)
        arr.push_back(A[i]);
    long long ans = 0;

    int l = 0, r = 0;
    for (int i = 1; i < N + L + 1; i++)
    {
        if (i < r)
        {
            Z[i] = min(r - i, Z[i - l]);
        }
        while (i + Z[i] < N + L + 1 && arr[Z[i]] == arr[Z[i] + i])
        {
            Z[i]++;
        }
        if (i + Z[i] > r)
        {
            r = i + Z[i];
            l = i;
        }
        // cout << Z[i] << " ";
    }

    for (int i = L + 1; i < N + L + 1; i++)
    {
        if (Z[i] == L)
            ans++;
    }
    cout << ans << "\n";
}
