// @check-accepted: esempi NE_10 L_equal
// @check-wrong-answer: N_small NE_1000 full
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long N, E;
    cin >> N >> E;
    long long P[N];
    long long L[N];

    for (int i = 0; i < N; i++)
    {
        cin >> P[i] >> L[i];
    }

    long long M[N + 1][E + 1];

    for (int i = 0; i <= N; i++)
    {
        M[i][0] = 0;
    }

    for (int i = 0; i <= E; i++)
    {
        M[0][i] = 0;
    }

    for (long long i = 1; i <= N; i++)
    {
        for (long long j = 1; j <= E; j++)
        {
            M[i][j] = M[i - 1][j];
            if (L[i - 1] <= j)
                M[i][j] = max(M[i][j], M[i - 1][j - L[i - 1]] + P[i - 1]);
        }
    }

    cout << M[N][E];
}
