#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int M, N;
    cin >> M >> N;
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<int>> map(M, vector<int>(N));
    vector<vector<int>> dp(M, vector<int>(N, -1));
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
        }
    }
    queue<pair<int, int>> q;
    q.push({0, 0});
    dp[0][0] = 0;
    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            bool insert = true;
            pair<int, int> check = {cur.first + directions[i].first, cur.second + directions[i].second};
            
            if (map[check.first][check.second] >= map[cur.first][cur.second] )

        
        }

    }

}
