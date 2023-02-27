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
    int N, M;
    cin >> N >> M;
    int position_x, position_y, direction;
    cin >> position_y >> position_x >> direction;
    int count = 0;

    vector<vector<int>> room(N, vector<int>(M));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> room[i][j];
            //cout << room[i][j] << " ";
        }
        //cout << "\n";
    }
    //cout << position_x << position_y << direction;

    while (true)
    {
        //cout << position_x << ", " << position_y << ", " << direction << ", " << room[position_x][position_y] << "\n";
        if (room[position_y][position_x] == 1) break;
        else if (room[position_y][position_x] == 0)
        {
            room[position_y][position_x] = 2;
            count += 1;
        }

        else if (
            room[position_y + 1][position_x] != 0 &&
            room[position_y - 1][position_x] != 0 &&
            room[position_y][position_x + 1] != 0 &&
            room[position_y][position_x - 1] != 0)
        {
            if (direction == 0) position_y += 1;
            if (direction == 1) position_x -= 1;
            if (direction == 2) position_y -= 1;
            if (direction == 3) position_x += 1;
        }
        else
        {
            direction = (direction + 3) % 4;
            if (direction == 0)
            {
                if (room[position_y - 1][position_x] == 0) position_y -= 1;
            }
            if (direction == 1)
            {
                if (room[position_y][position_x + 1] == 0) position_x += 1;
            }
            if (direction == 2)
            {
                if (room[position_y + 1][position_x] == 0) position_y += 1;
            }
            if (direction == 3)
            {
                if (room[position_y][position_x - 1] == 0) position_x -= 1;
            }
        }
    }
    cout << count;
}


