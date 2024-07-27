#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <array>
#include <random>
#include <map>
using namespace std;

int maxN;
int seed;
struct Input
{
    int n;
};

void print(const Input &input)
{
    cout << input.n << "\n";
}

mt19937 rng;
Input compute_input()
{
    Input input;
    uniform_int_distribution<int> genN(3, maxN);

    input.n = genN(rng);
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

    if (argc != 3)
    {
        cerr << "Usage: gen <maxN> <seed>\n";
        return 1;
    }

    maxN = atoi(argv[1]);
    seed = atoi(argv[2]);

    rng = mt19937(seed);
    Input input = getInput();

    print(input);
}