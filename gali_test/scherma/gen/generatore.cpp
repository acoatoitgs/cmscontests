#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <array>
#include <random>
using namespace std;

const int max_euro = 1000000000;
double exp_factor;
int maxN, _NE, seed;
bool sameL;
struct Input
{
    int n, e;
    vector<int> p, l;
};

void print(const Input &input)
{
    cout << input.n << " " << input.e << "\n";
    for (int i = 0; i < input.n; i++)
    {
        cout << input.p[i] << " " << input.l[i] << "\n";
    }
}

Input compute_input()
{
    // Could have been written better lol
    // will fix one day
    Input input;
    mt19937 rng(seed);

    uniform_int_distribution<int> preferred_variable(0, 1);
    uniform_int_distribution<int> ne_generator(1, ceil(sqrt(_NE)));
    if (preferred_variable(rng))
    {
        input.n = ne_generator(rng);
        input.e = _NE / input.n;
    }
    else
    {
        input.e = ne_generator(rng);
        input.n = _NE / input.e;
    }

    uniform_int_distribution<int> genEuro(1, max_euro);
    exponential_distribution<> exp_dist(exp_factor);

    if (sameL)
    {
        double exp_result = exp_dist(rng);
        int mapped_result = static_cast<int>(input.e * std::exp(-exp_result / (double)input.e));
        for (int i = 0; i < input.n; i++)
            input.l.push_back(mapped_result);
    }
    else
        for (int i = 0; i < input.n; i++)
        {
            double exp_result = exp_dist(rng);
            int mapped_result = static_cast<int>(input.e * std::exp(-exp_result / (double)input.e));

            input.l.push_back(mapped_result);
        }

    for (int i = 0; i < input.n; i++)
    {
        input.p.push_back(genEuro(rng));
    }

    return input;
}
bool validateInput(Input &input)
{
    for (int i = 0; i < input.n; i++)
        if (input.l[i] >= input.e)
            return false;
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

    if (argc < 6)
    {
        cerr << "Usage: gen <exp_factor> <maxN> <NE> <sameL> <seed>\n";
        return 1;
    }

    exp_factor = atof(argv[1]);
    maxN = atoi(argv[2]);
    _NE = atoi(argv[3]);
    sameL = atoi(argv[4]) == 1;
    seed = atoi(argv[5]);
    Input input = getInput();

    print(input);
}