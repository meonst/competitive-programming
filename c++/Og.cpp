#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while (true)
    {
        int L, R;
        cin >> L >> R;
        if (L == 0 && R == 0) break;
        cout << L + R << "\n";
    }
}
