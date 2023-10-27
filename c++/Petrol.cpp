#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b;
    cin >> a >> b;
    b += 60;
    ll sum;
    if (a >= b)
    {
        sum = b * 1500 + (a - b) * 3000;
    }
    else
    {
        sum = a * 1500;
    }

    cout << sum;
}
