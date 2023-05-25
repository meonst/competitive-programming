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
    int N;
    cin >> N;
    vector<string> map(N);
    vector<vector<int>> rotate
    {
      {-1, -1},
      {-1, 0},
      {-1, 1},
      {0, -1},
      {0, 1},
      {1, -1},
      {1, 0},
      {1, 1}
    };
    for (int i = 0; i < N; i++)
    {
        cin >> map[i];
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (map[i][j] == '.')
            {
                int count = 0;
                for (int k = 0; k < 8; k++)
                {
                    if (0 <= i + rotate[k][0] && i + rotate[k][0] < N && 0 <= j + rotate[k][1] && j + rotate[k][1] < N)
                    {
                        if (map[i + rotate[k][0]][j + rotate[k][1]] != '.')
                        {
                            count += map[i + rotate[k][0]][j + rotate[k][1]] - '0';
                        }
                    }
                }
                if (count > 9) 
                {
                    cout << 'M';
                }
                else
                {
                    cout << count;
                }
            }
            else
            {
                cout << '*';
            }
        }
        cout << "\n";
    }
}
