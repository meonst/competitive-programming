#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;

    if (s.size() == 4)
    {
        cout << 20;
    }
    else if (s.size() == 3)
    {
        if (s[1] == '0')
        {
            cout << s[2] - 38;
        }
        else
        {
            cout << s[0] - 38;
        }
    }
    else
    {
        cout << s[0] + s[1] - 96;
    }
}
