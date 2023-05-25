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
    vector<vector<int>> point(N, vector<int>(2));
    
    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        point[i][0] = x;
        point[i][1] = y;
    }

    int min_distance = 999999999;
    int min_index = 0;
    
    for (int i = 0; i < N; i++)
    {
        int max_distance_for_i = -1;
        for (int j = 0; j < N; j++)
        {
            int distance = pow(point[i][0] - point[j][0], 2) + pow(point[i][1] - point[j][1], 2);
            if (distance > max_distance_for_i)
                max_distance_for_i = distance;
        }
        if (max_distance_for_i < min_distance)
        {
            min_distance = max_distance_for_i;
            min_index = i;
        }
    }
    cout << point[min_index][0] << " " << point[min_index][1];
}
