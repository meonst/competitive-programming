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
    ll mod = 1000000007;
    vector<vector<ll>> dp(N, vector<ll>(3));
    dp[0] = {0, 0, 0};
    if (N >= 2) dp[1] = {0, 1, 1};
    for (int i = 2; i < N; i++)
    {
        dp[i] = 
        {
            (dp[i - 1][1] + dp[i - 1][2]) % mod,
            (dp[i - 1][0] + dp[i - 1][2]) % mod,
            (dp[i - 1][0] + dp[i - 1][1]) % mod
        };
    }
    cout << dp[N - 1][1];
}



// 0 1 2 =>
// 1 2 0
// 2 0 1