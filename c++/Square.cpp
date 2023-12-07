#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        ll a;
        cin >> a;
        cout << (a * (a + 1) * (2 * a + 1) / 6) << "\n";

    }
}
