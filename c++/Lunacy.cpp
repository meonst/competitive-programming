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
    double div = 0.167;
    while (true)
    {
        double a, b;
        cin >> a;
        b = a * div;
        if (a == -1) break;
        cout << "Objects weighing " << a << " on Earth will weigh " << b << " on the moon.\n";
    }
}
