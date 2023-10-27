#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, m;
    ll a = 1;
    cin >> n >> m;
    for (ll i = 0; i < n; i++)
    {
        ll b;
        cin >> b;
        a *= b;
        a %= m;
    }
    cout << a;
}
