#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <array>
#include <random>
using namespace std;

int maxN;
int maxL;
int maxV;
int option;
int seed;
struct Input
{
    int n, l;
    vector<int> A, B;
};

void print(const Input &input)
{
    cout << input.n << " " << input.l << "\n";
    for (auto i : input.A)
        cout << i << " ";
    cout << "\n";

    for (auto i : input.B)
        cout << i << " ";
    cout << "\n";
}

Input compute_input()
{
    Input input;
    mt19937 rng(seed);

    uniform_int_distribution<int> genN(2, maxN);
    uniform_int_distribution<int> genV(0, maxV);
    input.n = genN(rng);

    uniform_int_distribution<int> genL(2, min(input.n, maxL));
    input.l = genL(rng);

    input.A.resize(input.n);
    input.B.resize(input.l);
    uniform_int_distribution<int> mutation(0, 1000000);
    switch (option)
    {
    case 1:
        for (int i = 0; i < input.n; i++)
        {
            if (mutation(rng) == 42)
                input.A[i] = 1;
            else
                input.A[i] = 0;
        }

        for (int i = 0; i < input.l; i++)
        {
            if (mutation(rng) == 42)
                input.B[i] = 1;
            else
                input.B[i] = 0;
        }
        break;

    default:
        for (int i = 0; i < input.n; i++)
            input.A[i] = genV(rng);
        for (int i = 0; i < input.l; i++)
            input.B[i] = genV(rng);
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

    if (argc != 6)
    {
        cerr << "Usage: gen <maxN> <maxL> <maxV> <option> <seed>\n";
        return 1;
    }

    maxN = atoi(argv[1]);
    maxL = atoi(argv[2]);
    maxV = atoi(argv[3]);
    option = atoi(argv[4]);
    seed = atoi(argv[5]);
    Input input = getInput();

    print(input);
}