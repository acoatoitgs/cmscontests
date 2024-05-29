#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <array>
#include <random>
using namespace std;

long long maxN;
int seed;
struct Input
{
    long long n;
};

void print(const Input &input)
{
    cout << input.n << "\n";
}

Input compute_input()
{
    // Could have been written better lol
    // will fix one day
    Input input;
    mt19937 rng(seed);

    uniform_int_distribution<long long> gen(0, maxN);
    input.n = gen(rng);
    return input;
}
bool validateInput(Input &input)
{
    return (input.n <= maxN && input.n >= 1);
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

    maxN = atof(argv[1]);
    seed = atoi(argv[2]);
    Input input = getInput();

    print(input);
}