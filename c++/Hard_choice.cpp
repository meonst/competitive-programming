#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int ca, ba, pa, cr, br, pr;
    cin >> ca >> ba >> pa >> cr >> br >> pr;

    int s = 0;
    if (ca < cr) s += cr - ca;
    if (ba < br) s += br - ba;
    if (pa < pr) s += pr - pa;
    cout << s;
}
