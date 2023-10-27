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
    vector<int> c(12, 0);
    for (int i = 0; i < n; i++)
    {
        string a, b;
        cin >> a >> b;
        for (int j = 0; j < b.size(); j++)
        {
            if (b[j] == '/')
            {
                if (b[j + 1] == '1')
                {
                    if (b[j + 2] == '/')
                    {
                        c[b[j + 1] - 49] += 1;
                    }
                    else
                    {
                        c[b[j + 2] - 39] += 1;
                    }
                }
                else
                {
                    c[b[j + 1] - 49] += 1;
                }
                break;
            }
        }
    }

    for (int i = 0; i < 12; i++)
    {
        cout << i + 1 << " " << c[i] << "\n";
    }
}
