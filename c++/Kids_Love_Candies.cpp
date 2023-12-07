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
        int n, k;
        cin >> n >> k;
        int sum = 0;

        for (int j = 0; j < n; j++)
        {
            int a;
            cin >> a;
            sum += a / k;
        }
        cout << sum << "\n";
    }
}
