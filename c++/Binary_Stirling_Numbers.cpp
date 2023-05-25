#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


// S(0, 0) = 1; S(n, 0) = 0 for n > 0; S(0, m) = 0 for m > 0;
// S(n, m) = m S(n - 1, m) + S(n - 1, m - 1), for n, m > 0.
vector<vector<int>> sterling(100, vector<int>(100, -1));
int S(int N, int M)
{
    if (sterling[N][M] != -1)
    {
        return sterling[N][M];
    }

    if (N == 0 && M == 0)
    {
        sterling[N][M] = 1;
    }
    else if (N == 0 || M == 0)
    {
        sterling[N][M] = 0;
    }
    else 
    {
        sterling[N][M] = (M * S(N - 1, M) + S(N - 1, M - 1)) % 2;
    }
    return sterling[N][M];
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << "\n";
    for (int i = 0; i < 30; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            cout << S(i, j) << " ";
        }
        cout << "\n";
    }

}
