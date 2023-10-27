#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b, c, d, e, f, g, h;
    cin >> a >> b >> c >> d >> e >> f >> g >> h;
    if (a + b + c + d > e + f + g + h)
    {
        cout << (a + b + c + d);
    }
    else
    {
        cout << (e + f + g + h);
    }
}
