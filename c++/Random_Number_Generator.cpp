#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll m, a, c, X0, n, g;
    cin >> m >> a >> c >> X0 >> n >> g;
    
    a = a % m;
    c = c % m;
    
    vector<ll> X(n + 1);
    X[0] = X0;
    
    for (ll i = 1; i <= n; i++)
    {
        X[i] = ((a * X[i - 1] + c) % m); // % g;
        cout << X[i] << " ";
    }
    


}

// X[N] = (a ^ N * X) + ((a ^ N - 1) / (a - 1)) * c