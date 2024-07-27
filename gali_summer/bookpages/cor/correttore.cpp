#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <stdexcept>

using namespace std;

bool isValidPermutation(const vector<int> &pages)
{
    int n = pages.size();
    for (int i = 0; i < n - 2; ++i)
    {
        if ((pages[i] + pages[i + 1] + pages[i + 2]) % 3 != 0)
        {
            return false;
        }
    }
    return true;
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        cerr << "Usage: correttore_bookpages <input> <correct output> <test output>" << endl;
        return 1;
    }

    try
    {
        ifstream input(argv[1]);
        ifstream optimal(argv[2]);
        ifstream user(argv[3]);

        if (!input.is_open())
            throw runtime_error("Failed to open input file");
        if (!optimal.is_open())
            throw runtime_error("Failed to open correct output file");
        if (!user.is_open())
            throw runtime_error("Failed to open test output file");

        int N;
        if (!(input >> N) || N < 3)
        {
            throw runtime_error("Invalid input file format or value");
        }

        vector<int> optimal_pages(N);
        for (int i = 0; i < N; ++i)
        {
            if (!(optimal >> optimal_pages[i]) || optimal_pages[i] < 1 || optimal_pages[i] > N)
            {
                throw runtime_error("Invalid correct output file format or value");
            }
        }

        vector<int> user_pages(N);
        for (int i = 0; i < N; ++i)
        {
            if (!(user >> user_pages[i]) || user_pages[i] < 1 || user_pages[i] > N)
            {
                throw runtime_error("Invalid test output file format or value");
            }
        }

        set<int> optimal_set(optimal_pages.begin(), optimal_pages.end());
        set<int> user_set(user_pages.begin(), user_pages.end());

        if (optimal_set != user_set)
        {
            cout << "0.0" << endl;
            cerr << "translate:wrong" << endl;
        }
        else if (!isValidPermutation(user_pages))
        {
            cout << "0.0" << endl;
            cerr << "translate:wrong" << endl;
        }
        else
        {
            cout << "1.0" << endl;
            cerr << "translate:success" << endl;
        }

        input.close();
        optimal.close();
        user.close();
    }
    catch (const exception &e)
    {
        cout << "0.0" << endl;
        cerr << "translate:wrong" << endl;
    }
    return 0;
}
