
#include <string>
#include <iomanip>
#include <utility>
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <stdint.h>
#include <inttypes.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <unordered_map>
#include <numeric>
#include <algorithm>
using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string S;
    int N;
    cin >> S >> N;
    vector<vector<int>> slice(26, vector<int>(S.length(), 0));
    slice[S[0] - 97][0] = 1;
    for (int i = 1; i < S.length(); i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (S[i] - 97 == j)
            {
                slice[j][i] = slice[j][i - 1] + 1;
            }
            else
            {
                slice[j][i] = slice[j][i - 1];
            }
        }
    }
    // for (int i = 1; i < S.length(); i++)
    // {
    //     for (int j = 0; j < 26; j++)
    //     {
    //         cout << slice[j][i];
    //     }
    //     cout << "\n";
    // }

    char search;
    int start, end;
    for (int i = 0; i < N; i++)
    {
        cin >> search >> start >> end;
        if (start)
        {
            cout << slice[search - 97][end] - slice[search - 97][start - 1] << "\n";
        }
        else
        {
            cout << slice[search - 97][end] << "\n";
        }
    }
}
