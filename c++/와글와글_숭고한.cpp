#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int s, k, h;
    cin >> s >> k >> h;
    int m = min(s, min(k, h));
    int sum = s + k + h;

    if (sum >= 100) cout << "OK";
    else
    {
        if (m == s) cout << "Soongsil";
        if (m == k) cout << "Korea";
        if (m == h) cout << "Hanyang";
    }
}
