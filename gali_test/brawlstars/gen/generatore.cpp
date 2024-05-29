#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <array>
#include <random>
using namespace std;

int maxT, minA, maxA, minB, maxB, seed;
struct Input
{
    int t;
    vector<int> a, b;
};

void print(const Input &input)
{
    cout << input.t << "\n";
    for (int i = 0; i < input.t; i++)
    {
        cout << input.a[i] << " " << input.b[i] << "\n";
    }
}

Input compute_input()
{
    mt19937 rng(seed);
    uniform_int_distribution<int> genB(minB, maxB);
    uniform_int_distribution<int> genT(1, maxT);

    Input input;
    input.t = genT(rng);
    for (int i = 0; i < input.t; i++)
    {
        input.b.push_back(genB(rng));
        uniform_int_distribution<int>
            genA(minA, min(input.b.back(), maxA));

        input.a.push_back(genA(rng));
    }

    return input;
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (argc < 7)
    {
        cerr << "Usage: gen <maxT> <minA> <maxA> <minB> <maxB> <seed>\n";
        return 1;
    }

    maxT = atoi(argv[1]);
    minA = atoi(argv[2]);
    maxA = atoi(argv[3]);
    minB = atoi(argv[4]);
    maxB = atoi(argv[5]);
    seed = atoi(argv[6]);

    Input input = compute_input();

    print(input);
}