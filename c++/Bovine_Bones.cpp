#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> count(81, 0);
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            for (int k = 1; k <= c; k++)
            {
                count[i + j + k] += 1;
            }
        }
    }
    int maxi = -1;
    for (int i = 1; i <= 80; i++)
    {
        maxi = max(maxi, count[i]);
    }
    for (int i = 1; i <= 80; i++)
    {
        if (maxi == count[i])
        {
            cout << i;
            break;
        }
    }
}

