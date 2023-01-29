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
    vector<vector<int>> picture(100, vector<int>(100, 0));

    int N, M, x1, y1, x2, y2;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        for (int a = x1 - 1; a < x2; a++)
        {
            for (int b = y1 - 1; b < y2; b++)
            {
                picture[a][b] += 1;
            }
        }
    }
    int count = 0;
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (picture[i][j] > M) count += 1;
        }
    }
    cout << count;
}