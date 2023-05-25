#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    
    vector<vector<char>> site(N, vector<char>(M));
    vector<vector<int>> site_up(N, vector<int>(M, 0));
    vector<vector<int>> site_left(N, vector<int>(M, 0));

    for (int i = 0; i < N; i++)
    {
        string row;
        cin >> row;
        for (int j = 0; j < M; j++)
        {
            site[i][j] = row[j];
            if (site[i][j] == 'X') continue;

            site_up[i][j] = i == 0 ? 1 : site_up[i - 1][j] + 1;
            site_left[i][j] = j == 0 ? 1 : site_left[i][j - 1] + 1;
        }
    }
    int max = 0;

    cout << "\nleft\n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << site_left[i][j] << " ";
        }
        cout << "\n";
    }


    cout << "\nup\n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << site_up[i][j] << " ";
        }
        cout << "\n";
    }
}