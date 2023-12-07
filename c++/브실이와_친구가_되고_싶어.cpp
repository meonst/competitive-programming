#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b, k, x;
    cin >> a >> b >> k >> x;
    int c = 0;
    for (int i = a; i <= b; i++)
    {
        if (k - x <= i && i <= k + x) c++;
    }
    if (c > 0)
    {
        cout << c;
    }
    else
    {
        cout << "IMPOSSIBLE";
    }
}
