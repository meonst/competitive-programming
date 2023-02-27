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
    int N, A, B;
    int slope = -1;
    cin >> N;
    vector<vector<int>> points(N + 1, vector<int>(2));
    for (int i = 1; i <= N; i++)
    {
        cin >> points[i][0] >> points[i][1];
        for (int j = 1; j < i; j++)
        {
            int s = abs((points[j][1] - points[i][1]) / (points[j][0] - points[i][0]));
            if (s < slope) continue;
            if (s > slope)
            {
                slope = s;
                A = j;
                B = i;
            }
            else if (s == slope)
            {
                if (j < A)
                {
                    A = j;
                }
                else if (j == A)
                {
                    B = min(i, B);
                }
            }
        }
    }
    cout << A << " " << B;
}
