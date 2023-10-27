#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<ll> p(31);

    
    for (int i = 1; i <= 30; i++)
    {
        ll a = 1;
        for (int j = 1; j <= i; j++)
        {
            a *= (i + j);
            a /= j;
        }    
        a /= i + 1;
        p[i] = a;
    }

    while (true)
    {
        int a;
        cin >> a;
        if (a == 0) break;
        cout << p[a] << "\n";
    }
}

