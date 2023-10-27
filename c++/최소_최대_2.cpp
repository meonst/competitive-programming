#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        int maxi = -1000001;
        int mini = 1000001;
        int x;
        for (int j = 0; j < n; j++)
        {
            cin >> x;
            maxi = max(x, maxi);
            mini = min(x, mini);
        }
        cout << mini << " " << maxi << "\n";
    }
}
