#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll N;
    cin >> N;
    ll sum = 0;
    ll add = 1;
    while (N > 0)
    {
        sum += (N % 2) * add;
        N /= 2;
        add *= 3;
    }
    cout << sum;
}
