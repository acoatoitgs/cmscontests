// @check-accepted: square
// @check-runtime-error: example modular_skillissue full
// @check-zero: n_10
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
#pragma GCC optimize("Ofast")

struct point
{
    long long x, y;
};
const int mod = 1000000007;
int main()
{

    int N;
    cin >> N;

    vector<point> points(N);

    long long x, y;
    for (int i = 0; i < N; i++)
    {
        cin >> points[i].x >> points[i].y;
    }

    if (N != 4)
        return -1;

    long long x0 = points[0].x;
    long long x1 = (points[1].x == x0) ? points[2].x : points[1].x;

    long long y0 = points[0].y;
    long long y1 = (points[1].y == y0) ? points[2].y : points[1].y;

    cout << ((abs(x0 - x1) - 1) * (abs(y0 - y1) - 1)) % mod << "\n";
    return 0;
}
