#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int x, l, r;
    cin >> x >> l >> r;
    if (l <= x && x <= r)
    {
        cout << x;
    }
    else if (x < l)
    {
        cout << l;
    }
    else if (r < x)
    {
        cout << r;
    }
}
