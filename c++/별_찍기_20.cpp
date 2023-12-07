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
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 1) cout << " ";
        for (int j = 0; j < n; j++)
        {
            cout << "* ";
        }
        cout << "\n";        
    }
}
