#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    int ans_x, ans_y;
    for (int x = -999; x <= 999; x++)
    {
        for (int y = -999; y <= 999; y++)
        {
            if (a * x + b * y == c && d * x + e * y == f)
            {
                ans_x = x;
                ans_y = y;
            }
        }
    }
    cout << ans_x << " " << ans_y;
}
