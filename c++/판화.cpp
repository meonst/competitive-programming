#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;


bool outside(pair<int, int> point, char direction)
{
    if (direction == 'U')
    {
        if (point.first - 1 < 0) return true;
    }
    if (direction == 'D')
    {
        if (point.first + 1 >= N) return true;
    }
    if (direction == 'L')
    {
        if (point.second - 1 < 0) return true;
    }
    if (direction == 'R')
    {
        if (point.second + 1 >= N) return true;
    }
    return false;
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    // first is vertical, second is horizontal
    vector<vector<pair<bool, bool>>> plate(N, vector<pair<bool, bool>>(N));

    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            plate[i][j].first = false;
            plate[i][j].second = false;
        }
    }

    string route;
    cin >> route;
    pair<int, int> point = {0, 0};
    for (int i = 0; i < route.length(); i++)
    {
        if (outside(point, route[i])) continue;

        if (route[i] == 'U')
        {
            plate[point.first][point.second].first = true;
            point.first -= 1;
            plate[point.first][point.second].first = true;
        }
        if (route[i] == 'D')
        {
            plate[point.first][point.second].first = true;
            point.first += 1;
            plate[point.first][point.second].first = true;
        }
        if (route[i] == 'L')
        {
            plate[point.first][point.second].second = true;
            point.second -= 1;
            plate[point.first][point.second].second = true;
        }
        if (route[i] == 'R')
        {
            plate[point.first][point.second].second = true;
            point.second += 1;
            plate[point.first][point.second].second = true;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (plate[i][j].first && plate[i][j].second)
            {
                cout << "+";
            }
            if (plate[i][j].first && !plate[i][j].second)
            {
                cout << "|";
            }
            if (!plate[i][j].first && plate[i][j].second)
            {
                cout << "-";
            }
            if (!plate[i][j].first && !plate[i][j].second)
            {
                cout << ".";
            }
        }
        cout << "\n";
    }
}
