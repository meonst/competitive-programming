#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int a;
        cin >> a;
        
        if (a % 2 == 0)
        {
            cout << a << " is even\n";
        }
        else
        {
            cout << a << " is odd\n";
        }

    }
}
