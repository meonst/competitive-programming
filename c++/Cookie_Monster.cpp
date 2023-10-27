#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T, N, C;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> N >> C;
        cout << ((N / C) + (N % C ? 1 : 0)) << "\n";
    }
}
