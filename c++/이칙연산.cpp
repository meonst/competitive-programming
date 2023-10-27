#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll A, B, C;
    cin >> A >> B >> C;
    ll f = A * B / C;
    ll s = A * C / B;
    
    ll m = max(f, s);
    cout << m;
}

