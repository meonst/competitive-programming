#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    bool guilty = false;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string a;
        cin >> a;
        for (int j = 0; j < a.size(); j++)
        {
            if (a[j] == 'S')
            {
                guilty = true;
                break;
            }
        }
        if (guilty) 
        {
            cout << a;
            break;
        }
    }
}
