#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    string a;
    cin >> a;
    bool possible = true;
    for (int i = 0; i < a.size(); i++)
    {
        if (
            a[i] != 'I' &&
            a[i] != 'O' &&
            a[i] != 'S' &&
            a[i] != 'H' &&
            a[i] != 'Z' &&
            a[i] != 'X' &&
            a[i] != 'N'
        )
        {
            possible = false;
            break;
        }
    }
    cout << (possible ? "YES" : "NO");
}
