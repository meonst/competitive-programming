#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll w, h, p, q, t;
    cin >> w >> h >> p >> q >> t;

    int direction_x = 1;
    int direction_y = 1;

    p += t;
    q += t;
    bool returning_x = (p / w) % 2;
    bool returning_y = (q / h) % 2;
    p %= w;
    q %= h;

    if (returning_x) p = w - p;
    if (returning_y) q = h - q;    

    cout << p << " " << q;

}
