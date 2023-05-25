#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll k, a, b, c, d;
    cin >> k >> a >> b >> c >> d;
    if (k * a + b == k * c+ d)
    {
        cout << "Yes " << k * a + b;
    }
    else
    {
        cout << "No";
    }

}
