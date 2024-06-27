// @check-accepted: esempi N_30.K_30 N_30
// @check-time-limit-exceeded: K_30 full
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    vector<int> V(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> V[i];
    }

    int count = 0;

    // Quadruple nested loops to find all combinations (a, b, c, d) such that Va + Vb + Vc + Vd is a multiple of K
    for (int a = 0; a < N; ++a)
    {
        for (int b = a + 1; b < N; ++b)
        {
            for (int c = b + 1; c < N; ++c)
            {
                for (int d = c + 1; d < N; ++d)
                {
                    if ((V[a] + V[b] + V[c] + V[d]) % K == 0)
                    {
                        count++;
                    }
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}
