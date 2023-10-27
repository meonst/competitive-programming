#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    ll y = 0;
    ll m = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        ll length;
        cin >> length;

        y += (length / 30 + 1) * 10;
        m += (length / 60 + 1) * 15;
    }

    if (y < m)
    {
        cout << "Y " << y;
    }
    else if (y == m)
    {
        cout << "Y M " << y;
    }
    else if (y > m)
    {
        cout << "M " << m;
    }

}
