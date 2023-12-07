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
    for (int t = 0; t < T; t++)
    {

        int a;
        cin >> a;
        if (a == 1) 
        {
            cout << "#\n\n";
            continue;
        }
        for (int i = 0; i < a; i++)
        {
            cout << "#";
            for (int j = 0; j < a - 2; j++)
            {
                cout << ((i == 0 || i == a - 1) ? "#" : "J");
            }
            cout << "#\n";
        }
        cout << "\n";
    }
}
