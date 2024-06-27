#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <array>
#include <random>
using namespace std;

int maxN;
int maxK;
int maxV;
int seed;
struct Input
{
    int n, k;
    vector<int> V;
};

void print(const Input &input)
{
    cout << input.n << " " << input.k << "\n";
    for (auto i : input.V)
        cout << i << " ";
    cout << "\n";
}

Input compute_input()
{
    Input input;
    mt19937 rng(seed);

    uniform_int_distribution<int> genN(4, maxN);
    input.n = genN(rng);

    uniform_int_distribution<int> genK(2, maxK);
    input.k = genK(rng);

    input.V.resize(input.n);
    uniform_int_distribution<int> genV(1, maxV);

    for (int i = 0; i < input.n; i++)
    {
        input.V[i] = genV(rng);
    }

    return input;
}
bool validateInput(Input &input)
{
    return true;
}
Input getInput()
{
    Input i;

    do
    {
        i = compute_input();
    } while (!validateInput(i));

    return i;
}
int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (argc != 5)
    {
        cerr << "Usage: gen <maxN> <maxK> <maxV> <seed>\n";
        return 1;
    }

    maxN = atoi(argv[1]);
    maxK = atoi(argv[2]);
    maxV = atoi(argv[3]);
    seed = atoi(argv[4]);
    Input input = getInput();

    print(input);
}