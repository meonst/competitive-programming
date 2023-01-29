#include <iostream>
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
int a[10][10];
bool c[10][10];
bool c2[10][10];
bool c3[10][10];
int n = 9;
int cnt = 0;
int square(int x, int y)
{
    return (x / 3) * 3 + (y / 3);
}
bool go(int z)
{
    cnt += 1;
    if (z == 81 && cnt >= 10000000)
    {
        return true;
    }
    int x = z / n;
    int y = z % n;
    if (a[x][y] != 0)
    {
        return go(z + 1);
    }
    else
    {
        for (int i = 1; i <= 9; i++)
        {
            if (c[x][i] == 0 && c2[y][i] == 0 && c3[square(x, y)][i] == 0)
            {
                c[x][i] = c2[y][i] = c3[square(x, y)][i] = true;
                a[x][y] = i;
                if (go(z + 1))
                {
                    return true;
                }
                a[x][y] = 0;
                c[x][i] = c2[y][i] = c3[square(x, y)][i] = false;
            }
        }
    }
    return false;
}
int asdf()
{
    vector<vector<int>> zeros(9, vector<int>(9, 1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = rand() % 10;
            if (a[i][j] != 0)
            {
                c[i][a[i][j]] = true;
                c2[j][a[i][j]] = true;
                c3[square(i, j)][a[i][j]] = true;
            }
            else
            {
                zeros[i][j] = 0;
            }
        }
    }
    if (go(0))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << "\n";
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << zeros[i][j] << " ";
            }
            cout << "\n";
        }
        return 1;
    }
    return 0;
}

int main()
{
    for (long j = 0; j < 10000000; j++)
    {
        if (asdf() == 1)
            break;
    }
}
