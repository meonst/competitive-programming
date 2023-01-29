
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

int N, M , a, x, xx, y, yy;
int summer = 0;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    vector<vector<int>> sum(N + 1, vector<int>(N + 1, 0));

    cin >> sum[1][1];
    for (int i = 2; i < N + 1; i++)
    {
        cin >> a;
        sum[1][i] = sum[1][i - 1] + a;
    }
    
    for (int i = 2; i < N + 1; i++)
    {
        cin >> a;
        summer = a;
        sum[i][1] = sum[i - 1][1] + summer;
        for (int j = 2; j < N + 1; j++)
        {
            cin >> a;
            summer += a;
            sum[i][j] = sum[i - 1][j] + summer;
        }
    }

    // for (int i = 0; i < N + 1; i++)
    // {
    //     for (int j = 0; j < N + 1; j++)
    //     {
    //         cout << sum[i][j] << " ";
    //     }
    //     cout << "\n";
    // }


    for (int i = 0; i < M; i++)
    {
        
        cin >> x >> y >> xx >> yy;
        
        summer = sum[xx][yy] - sum[xx][y - 1] - sum[x - 1][yy] + sum[x - 1][y - 1];

        cout << summer << "\n";
    }
}
