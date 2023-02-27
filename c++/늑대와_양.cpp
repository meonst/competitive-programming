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
#include <regex>
#include <stdio.h>
#include <stdlib.h>
#include <cassert>
#include <queue>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int R, C;
    string in;
    bool doomed = false;
    cin >> R >> C;
    vector<vector<string>> farm(R + 2, vector<string>(C + 2, "."));
    for (int i = 1; i < R + 1; i++)
    {
        cin >> in;
        for (int j = 0; j < C; j++)
        {
            farm[i][j + 1] = in[j];
        }
    }

    for (int i = 1; i < R + 1; i++)
    {
        for (int j = 1; j < C + 1; j++)
        {
            if (farm[i][j] == ".") continue;
            else if (farm[i][j] == "S")
            {
                if (farm[i + 1][j] == ".") farm[i + 1][j] = "D";
                if (farm[i - 1][j] == ".") farm[i - 1][j] = "D";
                if (farm[i][j + 1] == ".") farm[i][j + 1] = "D";
                if (farm[i][j - 1] == ".") farm[i][j - 1] = "D";
            }
            else if (farm[i][j] == "W")
            {
                if (farm[i + 1][j] == "S") doomed = true;
                if (farm[i - 1][j] == "S") doomed = true;
                if (farm[i][j + 1] == "S") doomed = true;
                if (farm[i][j - 1] == "S") doomed = true;
            }
        }
    }
    if (doomed) cout << 0;
    else
    {
        cout << 1 << "\n";
        for (int i = 1; i < R + 1; i++)
        {
            for (int j = 1; j < C + 1; j++)
            {
                cout << farm[i][j];
            }
            cout << "\n";
        }
    }
}
