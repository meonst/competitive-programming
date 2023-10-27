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
        double a;
        cin >> a;
        a *= 0.8;

        cout << fixed << showpoint;
        cout << setprecision(2);
        cout << "$" << a << "\n";
    }
}
