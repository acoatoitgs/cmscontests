#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <array>
#include <random>
using namespace std;

int maxN;
int minV;
int maxV;
int seed;
struct Input
{
    int n;
    vector<int> V;
};

void print(const Input &input)
{
    cout << input.n << "\n";
    for (auto i : input.V)
        cout << i << " ";
    cout << "\n";
}

Input compute_input()
{
    Input input;
    mt19937 rng(seed);

    uniform_int_distribution<int> genN(1, maxN);
    input.n = genN(rng);

    uniform_int_distribution<int> genV(minV, maxV);
    input.V.resize(input.n);

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
        cerr << "Usage: gen <maxN> <minV> <maxV> <seed>\n";
        return 1;
    }

    maxN = atoi(argv[1]);
    minV = atoi(argv[2]);
    maxV = atoi(argv[3]);
    seed = atoi(argv[4]);
    Input input = getInput();

    print(input);
}