// @check-accepted: example square n_10
// @check-time-limit-exceeded: modular_skillissue full
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
#pragma GCC optimize("Ofast")

const int mod = 1000000007;
const double EPS = 1e-9;

struct point
{

    long long x, y;

    point()
    {
        x = y = 0.0;
    }
    point(long long _x, long long _y) : x(_x), y(_y) {}

    bool operator==(point other) const
    {
        return (abs(x - other.x) < EPS && (abs(y - other.y) < EPS));
    }

    bool operator<(const point &p) const
    {
        return x < p.x || (abs(x - p.x) < EPS && y < p.y);
    }
};

int orientation(const point &p, const point &q, const point &r)
{
    long long val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0)
        return 0;             // collinear
    return (val > 0) ? 1 : 2; // clock or counterclock wise
}

bool onSegment(const point &p, const point &q, const point &r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
        return true;
    return false;
}

bool doIntersect(const point &p1, const point &q1, const point &p2, const point &q2)
{
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    // General case
    if (o1 != o2 && o3 != o4)
        return true;

    // Special Cases
    // p1, q1 and p2 are collinear and p2 lies on segment p1q1
    if (o1 == 0 && onSegment(p1, p2, q1))
        return true;

    // p1, q1 and q2 are collinear and q2 lies on segment p1q1
    if (o2 == 0 && onSegment(p1, q2, q1))
        return true;

    // p2, q2 and p1 are collinear and p1 lies on segment p2q2
    if (o3 == 0 && onSegment(p2, p1, q2))
        return true;

    // p2, q2 and q1 are collinear and q1 lies on segment p2q2
    if (o4 == 0 && onSegment(p2, q1, q2))
        return true;

    return false; // Doesn't fall in any of the above cases
}

bool isSelfIntersecting(vector<point> &polygon, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            // Check if the current pair of segments (i, i+1) and (j, j+1) intersect
            int next_i = (i + 1) % n;
            int next_j = (j + 1) % n;

            // Ensure that we don't check adjacent segments which share a common point
            if (next_i == j || next_j == i)
                continue;

            if (doIntersect(polygon[i], polygon[next_i], polygon[j], polygon[next_j]))
                return true;
        }
    }
    return false;
}

int pointsOnSegment(const point &p1, const point &p2)
{
    long long delta_x = abs(p2.x - p1.x);
    long long delta_y = abs(p2.y - p1.y);

    long long seg = gcd(delta_x, delta_y);

    return seg;
}

long long getSurface(vector<point> &P, int N)
{
    long long ans = 0;
    for (int i = 0; i < N - 1; ++i)
    {
        ans += (P[i].x * P[i + 1].y - P[i + 1].x * P[i].y);
    }

    ans += (P[N - 1].x * P[0].y - P[0].x * P[N - 1].y);

    return abs(ans) / 2;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<point> points(N);

    long long x, y;
    for (int i = 0; i < N; i++)
    {
        cin >> points[i].x >> points[i].y;
    }

    long long best = -1;
    sort(points.begin(), points.end());

    do
    {
        for (int k = 3; k <= N; k++)
        {
            if (isSelfIntersecting(points, k))
                continue;
            long long perimeter = 0;
            for (int i = 0; i < k; i++)
            {
                perimeter += pointsOnSegment(points[i], points[(i + 1) % k]);
            }
            long long surface = getSurface(points, k);
            long long inside_points = surface + 1 - (perimeter >> 1);
            best = max(best, inside_points);
        }
    } while (next_permutation(points.begin(), points.end()));

    cout << best % mod << "\n";

    return 0;
}
