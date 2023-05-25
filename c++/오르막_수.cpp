#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    vector<vector<int>> dp(N + 1, vector<int>(10));
    for (int i = 0; i < 10; i++)
    {
        dp[1][i] = 1;
    }
    for (int i = 2; i <= N; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k <= j; k++)
            {
                dp[i][j] += dp[i - 1][k];
                dp[i][j] %= 10007;
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < 10; i++) sum += dp[N][i];
    cout << sum % 10007;
}
