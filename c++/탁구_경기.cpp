#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int D = 0;
    int P = 0;

    for (int i = 0; i < n; i++)
    {
        char w;
        cin >> w;
        if (w == 'D') D++;
        if (w == 'P') P++;

        if (D > P + 1) break;
        if (P > D + 1) break;
    }

    cout << D << ":" << P;
}
