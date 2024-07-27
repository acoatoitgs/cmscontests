#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <cctype>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        cerr << "Usage: correttore <input> <correct output> <test output>" << endl;
        return 1;
    }
    string line;
    int K;

    try
    {
        ifstream input(argv[1]);
        ifstream optimal(argv[2]);
        ifstream user(argv[3]);
        if (!input)
            throw runtime_error("Failed to open input file");
        if (!optimal)
            throw runtime_error("Failed to open test optimal file");
        if (!user)
            throw runtime_error("Failed to open test user file");

        input >> K;

        int opt_len;
        optimal >> opt_len;

        user >> line;

        int user_len = stoi(line);
        if (user_len != opt_len)
        {
            cout << "0.0" << endl;
            cerr << "translate:wrong" << endl;
        }
        else
        {
            vector<int> user_arr;
            while (user_len)
            {
                try
                {
                    user >> line;
                    int num = stoi(line);
                    user_arr.emplace_back(num);
                }
                catch (const exception &e)
                {
                    cout << "0.0" << endl;
                    cerr << "translate:wrong" << endl;
                    goto end;
                }
                user_len--;
            }

            int sum = 0;
            for (auto e : user_arr)
                sum += e * e;
            if (sum == K)
            {
                cout << "1.0" << endl;
                cerr << "translate:success" << endl;
            }
            else
            {
                cout << "0.0" << endl;
                cerr << "translate:wrong" << endl;
            }
        }
    end:
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
