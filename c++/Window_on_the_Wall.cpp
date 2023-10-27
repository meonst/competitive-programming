#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int w, h, d;

    cin >> w >> h >> d;

    w -= 2 * d;
    h -= 2 * d;
    if (w < 0 || h < 0) cout << 0;
    else cout << w * h;
}
