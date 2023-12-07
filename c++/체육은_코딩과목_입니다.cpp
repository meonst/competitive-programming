#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int r = 0;
    int l = 0;
    int b = 0;
    for (int i = 0; i < 10; i++)
    {
        int a;
        cin >> a;
        if (a == 1) r++;
        if (a == 2) b++;
        if (a == 3) l++;
    }
    int sum = r + (2 * b) + (3 * l);
    if (sum % 4 == 0)
    {
        cout << "N";
    }
    if (sum % 4 == 1)
    {
        cout << "E";
    }
    if (sum % 4 == 2)
    {
        cout << "S";
    }
    if (sum % 4 == 3)
    {
        cout << "W";
    }

}
