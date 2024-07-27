#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <array>
#include <random>
#include <map>
using namespace std;

int maxN;
int minV;
int maxV;
int option;
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
    uniform_int_distribution<int> genN(1, maxN);
    uniform_int_distribution<int> genSqr(1, sqrt(maxN));
    switch (option)
    {
    case 1:
        input.n = genSqr(rng);
        input.n *= input.n;
        break;
    default:
        input.n = genN(rng);
        break;
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

    if (argc != 4)
    {
        cerr << "Usage: gen <maxN> <option> <seed>\n";
        return 1;
    }

    maxN = atoi(argv[1]);
    option = atoi(argv[2]);
    seed = atoi(argv[3]);

    rng = mt19937(seed);
    Input input = getInput();

    print(input);
}