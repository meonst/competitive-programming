#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T, N, M;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> N >> M;
        int max = -1;
        int winner = 0;
        vector<int> votes(N, 0);
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                int v;
                cin >> v;
                votes[j] += v;
            }
        }

        for (int i = 0; i < N; i++)
        {
            if (max < votes[i])
            {
                max = votes[i];
                winner = i + 1;
            }
        }

        cout << winner << "\n";
    }
}
