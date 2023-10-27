#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll N, k;
    cin >> N >> k;
    if (k == 1) N *= 11;
    if (k == 2) N *= 111;
    if (k == 3) N *= 1111;
    if (k == 4) N *= 11111;
    if (k == 5) N *= 111111;
    cout << N;
}
