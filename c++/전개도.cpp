#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// https://www.acmicpc.net/problem/1917 랑 비슷한 문제
vector<vector<int>> neighbors = {
    {4, 2, 3, 5},
    {4, 2, 3, 5}, // 1
    {4, 6, 3, 1}, // 2
    {1, 2, 6, 5}, // 3
    {6, 2, 1, 5}, // 4
    {4, 1, 3, 6}, // 5
    {4, 5, 3, 2}  // 6
};
vector<vector<int>> square(vector<vector<int>> b)
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
    return b;
}
bool foldable(vector<vector<int>> b)
{
    int sum = 0;
    for (int i = 1; i < 7; i++)
    {
        for (int j = 1; j < 7; j++)
        {
            if (b[i][j] != 7) sum += b[i][j];
        }
    }
    return (sum == 21);
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int x;
    vector<vector<int>> original(8, vector<int>(8, 0));
    vector<vector<int>> blueprint(8, vector<int>(8, 0));
    for (int j = 1; j < 7; j++)
    {
        for (int k = 1; k < 7; k++)
        {
            cin >> x;
            if (x != 0)
            {
                blueprint[j][k] = 7;
                original[j][k] = x;
            }
        }
    }
    blueprint = square(blueprint);
    if (foldable(blueprint))
    {
        pair<int, int> where_is_one;
        pair<int, int> where_is_ones_oppposite;
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                if (original[i][j] == 1)
                {
                    where_is_one.first = i;
                    where_is_one.second = j;
                }
            }
        }
        int opposite_number = 7 - blueprint[where_is_one.first][where_is_one.second];
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                if (blueprint[i][j] == opposite_number)
                {
                    where_is_ones_oppposite.first = i;
                    where_is_ones_oppposite.second = j;
                }
            }
        }
        cout << original[where_is_ones_oppposite.first][where_is_ones_oppposite.second];
    }
    else
    {
        cout << 0;
    }
}
