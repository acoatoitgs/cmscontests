// @check-accepted: esempi N_100,V_i>=0 N_100
// @check-time-limit-exceeded: V_i>=0 full
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

const long long MOD = 1000000007;

long long calculateEvanNumber(const std::vector<int> &A)
{
    int N = A.size();
    std::vector<int> sortedA;
    long long E = 1;

    for (int i = 1; i <= N; ++i)
    {
        sortedA.push_back(A[i - 1]);
        std::sort(sortedA.begin(), sortedA.end());

        long long f_i = 0;
        for (int j = 0; j < i; ++j)
        {
            f_i += sortedA[j] * (j + 1);
            f_i %= MOD; // Apply modulo operation to avoid overflow
        }
        f_i = std::abs(f_i); // Take the absolute value
        E = (E * f_i) % MOD; // Update E and apply modulo operation
    }

    return E;
}

int main()
{
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for (int i = 0; i < N; ++i)
    {
        std::cin >> A[i];
    }

    std::cout << calculateEvanNumber(A) << std::endl;

    return 0;
}
