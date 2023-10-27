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
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        ll sum = 0;
        for (int i = 1; i <= a; i++)
        {
            sum += i * (i + 1) * (i + 2) / 2;
        }
        cout << sum << "\n";
    }
}
