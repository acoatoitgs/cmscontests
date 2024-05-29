#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <array>
#include <random>
using namespace std;

struct Input
{
    int N;
    vector<int> H;
};

void print(const Input &input)
{
    cout << input.N << "\n";
    for (auto i : input.H)
        cout << i << " ";
    cout << "\n";
}

void compute_input(int N, int maxH, bool sameH, int seed, Input &input)
{
    mt19937 rng(seed);
    uniform_int_distribution<int> rnd(1, maxH);

    input.N = N;
    input.H.resize(N);
    if (sameH)
    {
        int gen = rnd(rng);
        for (int i = 0; i < N; i++)
            input.H[i] = gen;
        return;
    }
    for (int i = 0; i < N; i++)
    {
        input.H[i] = rnd(rng);
    }
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (argc < 5)
    {
        cerr << "Usage: gen <N> <maxH> <sameH> <seed>\n";
        return 1;
    }

    int N = atoi(argv[1]);
    int maxH = atoi(argv[2]);
    int sameH = atoi(argv[3]) != 0;
    int seed = atoi(argv[4]);

    Input input;
    compute_input(N, maxH, sameH, seed, input);
    /*
    if (strcmp(argv[1], "random") == 0)
    {
        gen_random(N, Q, max_coord, seed, input);
    }
    else
    {
        cerr << "Unrecognized type.\n";
        return 1;
    }   */

    print(input);
}