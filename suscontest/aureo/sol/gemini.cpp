// @check-wrong-answer: esempi N_100,V_i>=0 N_100
// @check-zero: V_i>=0 full
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

long long f(vector<int> &s, int i)
{
    long long res = 0;
    for (int j = 0; j < i; j++)
    {
        res = (res + (s[j] * (j + 1))) % MOD;
    }
    return res;
}

long long E(vector<int> &A)
{
    int N = A.size();
    vector<int> s(N);
    long long res = 1;

    for (int i = 1; i <= N; i++)
    {
        copy_n(A.begin(), i, s.begin());
        sort(s.begin(), s.end(), greater<int>());
        res = (res * f(s, i)) % MOD;
    }

    return res;
}

int main()
{
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    cout << E(A) << endl;

    return 0;
}
