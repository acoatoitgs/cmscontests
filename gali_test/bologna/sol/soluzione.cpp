// @check-accepted: esempi H_uguale N_piccolo N_grande
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; i++)
        cin >> H[i];

    cout << *min_element(H.begin(), H.end()) << "\n";
}
