#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string kda;
    cin >> kda;

    int k = -1;
    int d = -1;
    int a = -1;
    
    int last = 0;

    for (int i = 0; i < kda.size(); i++)
    {
        if (kda[i] == '/')
        {
            if (k == -1)
            {
                if (i == 1)
                {
                    k = kda[i - 1] - 48;
                }
                else
                {
                    k = (kda[i - 2] - 48) * 10 + (kda[i - 1] - 48);
                }
            }
            else if (d == -1)
            {
                if (kda[i - 2] == '/')
                {
                    d = kda[i - 1] - 48;
                }
                else
                {
                    d = (kda[i - 2] - 48) * 10 + (kda[i - 1] - 48);
                }
            }
        }
    }

    if (kda[kda.size() - 2] == '/')
    {
        a = kda[kda.size() - 1] - 48;
    }
    else
    {
        a = (kda[kda.size() - 2] - 48) * 10 + (kda[kda.size() - 1] - 48);
    }
    cout << ((k + a < d || d == 0) ? "hasu" : "gosu");
}
