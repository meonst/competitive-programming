#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    double a, b;
    while (true)
    {
        cin >> a >> b;
        if (a == 0 && b == 0) 
        {
            cout << "AXIS";
            break;
        }

        if (a == 0 || b == 0)
        {
            cout << "AXIS\n";
        }
        else
        {
            if (a > 0 && b > 0)
                cout << "Q1\n";
            if (a < 0 && b > 0)
                cout << "Q2\n";
            if (a < 0 && b < 0)
                cout << "Q3\n";
            if (a > 0 && b < 0)
                cout << "Q4\n";
        }
    }
}
