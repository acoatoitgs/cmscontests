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
    vector<pair<int, int>> V;
};

void print(const Input &input)
{
    cout << input.n << "\n";
    for (auto i : input.V)
        cout << i.first << " " << i.second << "\n";
}

mt19937 rng;
Input compute_input()
{
    Input input;
    uniform_int_distribution<int> genN(3, maxN);
    uniform_int_distribution<int> genV(minV, maxV);

    switch (option)
    {
    // Square option
    case 1:
    {
        input.n = 4;
        input.V.resize(input.n);
        int x0 = genV(rng);
        int x1 = genV(rng);
        int y0 = genV(rng);
        int y1 = genV(rng);
        input.V[0] = {x0, y0};
        input.V[1] = {x1, y0};
        input.V[2] = {x0, y1};
        input.V[3] = {x1, y1};
        break;
    }

    default:
    {
        input.n = genN(rng);
        input.V.resize(input.n);
        for (int i = 0; i < input.n; i++)
        {
            input.V[i] = {genV(rng), genV(rng)};
        }
        break;
    }
    }

    return input;
}

bool validateInput(Input &input)
{
    if (option == 1)
    {
        if (input.V[0].first == input.V[1].first && input.V[1].first == input.V[2].first)
            return false;
        if (input.V[0].second == input.V[1].second && input.V[1].second == input.V[2].second)
            return false;
    }
    map<pair<int, int>, bool> mp;
    for (auto i : input.V)
    {
        if (mp[i])
            return false;
        mp[i] = 1;
    }

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
        cerr << "Usage: gen <maxN> <minV> <maxV> <option> <seed>\n";
        return 1;
    }

    maxN = atoi(argv[1]);
    minV = atoi(argv[2]);
    maxV = atoi(argv[3]);
    option = atoi(argv[4]);
    seed = atoi(argv[5]);
    rng = mt19937(seed);
    Input input = getInput();

    print(input);
}