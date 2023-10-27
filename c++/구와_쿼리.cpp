#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll N, M, x, y, z, r, count, R, a, b, c, sum;
    scanf("%d", &N);
    vector<vector<ll>> dots(N, vector<ll>(3));
    vector<ll> dots_squared_sum(N);
    for (ll i = 0; i < N; i++)
    {
        scanf("%d %d %d", &dots[i][0], &dots[i][1], &dots[i][2]);
        dots_squared_sum[i] = dots[i][0] * dots[i][0] + dots[i][1] * dots[i][1] + dots[i][2] * dots[i][2];
    }
    scanf("%d", &M);
    for (ll i = 0; i < M; i++)
    {
        scanf("%d %d %d %d", &x, &y, &z, &r);
        R = r * r;
        sum = x * x + y * y + z * z;
        count = 0;
        for (int j = 0; j < N; j++)
        {
            if (R < sum - 2 * (x * dots[j][0] + y * dots[j][1] + z * dots[j][2]) + dots_squared_sum[j]) continue;   
            count++;
        }
        cout << count << "\n";
    }
}
