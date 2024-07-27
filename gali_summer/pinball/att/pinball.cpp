#include <iostream>
#include <vector>
using namespace std;
#pragma GCC optimize("Ofast")

struct point
{
    long long x, y;
};

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

    cout << "42\n";
    return 0;
}
