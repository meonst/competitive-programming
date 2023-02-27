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

vector<vector<int>> neighbors = {
    {4, 2, 3, 5},
    {4, 2, 3, 5}, // 1
    {4, 6, 3, 1}, // 2
    {1, 2, 6, 5}, // 3
    {6, 2, 1, 5}, // 4
    {4, 1, 3, 6}, // 5
    {4, 5, 3, 2}  // 6
};
bool square(vector<vector<int>> b)
{
    vector<bool> done(7, false);

    for (int i = 1; i < 7; i++)
    {
        for (int j = 1; j < 7; j++)
        {
            if (b[i][j] == 7)
            {
                b[i][j] = 1;
                if (b[i][j + 1] == 7) b[i][j + 1] = 2;
                if (b[i + 1][j] == 7) b[i + 1][j] = 3;
                done[1] = true;
            }
            if (done[1])
                break;
        }
        if (done[1])
            break;
    }

    for (int k = 0; k < 7; k++)
    {
        for (int i = 1; i < 7; i++)
        {
            for (int j = 1; j < 7; j++)
            {
                for (int eye = 2; eye < 7; eye++)
                {
                    if (!done[eye] && b[i][j] == eye)
                    {
                        done[eye] = true;
                        int rotation = 0;
                        //get rotation
                        for (int l = 0; l < 4; l++)
                        {
                            if (b[i - 1][j] == neighbors[eye][l])
                            {
                                rotation = 4 - l;
                            }
                            else if (b[i][j + 1] == neighbors[eye][l])
                            {
                                rotation = 5 - l;
                            }
                            else if (b[i + 1][j] == neighbors[eye][l])
                            {
                                rotation = 6 - l;
                            }
                            else if (b[i][j - 1] == neighbors[eye][l])
                            {
                                rotation = 7 - l;
                            }
                        }
                        //cout << "1: " << eye << ", " << rotation << "\n";
                        // change neighbors from 7 to their relative location on the die
                        if (b[i - 1][j] == 7) 
                        {
                            b[i - 1][j] = neighbors[eye][(8 - rotation) % 4];
                        }
                        if (b[i][j + 1] == 7) 
                        {
                            b[i][j + 1] = neighbors[eye][(9 - rotation) % 4];
                        }
                        if (b[i + 1][j] == 7) 
                        {
                            b[i + 1][j] = neighbors[eye][(10 - rotation) % 4];
                        }
                        if (b[i][j - 1] == 7) 
                        {
                            b[i][j - 1] = neighbors[eye][(11 - rotation) % 4];
                        }
                        
                    }

                }
            }
        }
    }

    int sum = 0;
    for (int i = 1; i < 7; i++)
    {
        for (int j = 1; j < 7; j++)
        {
            //cout << b[i][j] << " ";
            if (b[i][j] != 7) sum += b[i][j];
        }
        //cout << "\n";
    }
    return (sum == 21);
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int x;
    for (int i = 0; i < 3; i++)
    {
        vector<vector<int>> blueprint(8, vector<int>(8, 0));
        for (int j = 1; j < 7; j++)
        {
            for (int k = 1; k < 7; k++)
            {
                cin >> x;
                if (x == 1)
                    blueprint[j][k] = 7;
            }
        }
        cout << (square(blueprint) ? "yes" : "no") << "\n";
    }
}
