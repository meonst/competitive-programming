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

string a;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<vector<int>> directions{
        {-1, -1},
        {-1, 0},
        {-1, 1},
        {0, -1},
        {0, 1},
        {1, -1},
        {1, 0},
        {1, 1},
    };
    while (true)
    {
        int R, C;
        cin >> R >> C;
        if (R == 0 && C == 0) break;
        vector<vector<char>> map(R + 2, vector<char>(C + 2, 49));
        for (int i = 1; i <= R; i++)
        {
            cin >> a;
            for (int j = 0; j < C; j++)
            {
                map[i][j + 1] = a[j];
            }
        }
        for (int i = 1; i <= R; i++)
        {
            for (int j = 1; j <= C; j++)
            {
                if (map[i][j] == 46)
                {
                    int count = 0;
                    for (int k = 0; k < 8; k++)
                    {
                        if (map[i + directions[k][0]][j + directions[k][1]] == 42)
                        {
                            count += 1;
                        }
                    }
                    map[i][j] = count + 48;
                }
                cout << map[i][j];
            }
            cout << "\n";
        }

    }
}
