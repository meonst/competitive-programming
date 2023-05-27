#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while (true)
    {
        string a;
        cin >> a;
        if (a == "0") break;
        int length = 0;
        length += a.size() + 1;
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] == 48)
            {
                length += 4;
            }
            else if (a[i] == 49)
            {
                length += 2;
            }
            else
            {
                length += 3;
            }
        }
        cout << length << "\n";
    }
    
}
