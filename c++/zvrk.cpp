#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll zvrk_sum(ll n)
{
    if (n < 2) return n;
    return (n / 2 + 2 * zvrk_sum(n / 2) + n % 2);
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll A, B;
    cin >> A >> B;
    cout << zvrk_sum(B) - zvrk_sum(A - 1);
}