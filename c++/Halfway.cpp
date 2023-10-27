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
    ll all = N * (N - 1) / 2;
    ll half;
    if (all % 2 == 0)
    {
        half = all / 2;
    }
    else
    {
        half = all / 2;
        half += 1;
    }
    ll start = 0;
    while (half > 0)
    {
        half -= (N - start - 1);
        start += 1;
    }
    cout << start;


}
