#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int f1, f2;
    cin >> f1 >> f2;
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int a;
        cin >> a;
        if (a <= 1000)
        {
            cout << a << " " << a * f1;
        }
        else
        {
            cout << a << " " << 1000 * f1 + (a - 1000) * f2;
        }
        cout << "\n";
    }
}
