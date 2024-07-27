// @check-accepted: example square n_10 modular_skillissue full
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
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

struct vec
{
    long long x, y;
    vec(long long _x, long long _y) : x(_x), y(_y) {}
};

vec toVec(point a, point b)
{
    return vec(b.x - a.x, b.y - a.y);
}

long long cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }

bool ccw(point p, point q, point r)
{
    return cross(toVec(p, q), toVec(p, r)) > 0;
}

vector<point> CH_Andrew(vector<point> &Pts)
{
    int n = Pts.size(), k = 0;
    vector<point> H(2 * n, point(0x3f3f3f3f, 0x3f3f3f3f));
    sort(Pts.begin(), Pts.end());

    for (int i = 0; i < n; ++i)
    {

        while ((k >= 2) && !ccw(H[k - 2], H[k - 1], Pts[i]))
            --k;

        H[k++] = Pts[i];
    }

    for (int i = n - 2, t = k + 1; i >= 0; --i)
    {
        while ((k >= t) && !ccw(H[k - 2], H[k - 1], Pts[i]))
            --k;
        H[k++] = Pts[i];
    }

    return H;
}

int pointsOnSegment(point &p1, point &p2)
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

    vector<point> ch = CH_Andrew(points);
    int ch_len;
    set<point> st;
    for (int i = 0; i < ch.size(); i++)
    {
        if (st.find(ch[i]) != st.end())
        {
            ch_len = i;
            break;
        }
        st.insert(ch[i]);
    }

    long long perimeter = 0;
    for (int i = 0; i < ch_len; i++)
    {
        perimeter += pointsOnSegment(ch[i], ch[i + 1]);
    }
    long long surface = getSurface(ch, ch_len);
    long long inside_points = surface + 1 - (perimeter >> 1);
    cout << inside_points % mod << "\n";

    return 0;
}
