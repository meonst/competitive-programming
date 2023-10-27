#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << fixed << showpoint;
    cout << setprecision(2);

    while (true)
    {
        double n;
        cin >> n;
        if (n == 0) break;
        double answer = pow(n, 0) + pow(n, 1) + pow(n, 2) + pow(n, 3) + pow(n, 4);
        cout << answer << "\n";
    }
}
