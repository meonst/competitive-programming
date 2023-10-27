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
    for (int i = n + 1; ; i++)
    {
        bool no_zero = true;
        int next = i;
        while (next >= 10)
        {
            if (next % 10 == 0)
            {
                no_zero = false;
                break;
            }
            next /= 10;
        }
        if (no_zero)
        {
            cout << i;
            break;
        }
    }
}
