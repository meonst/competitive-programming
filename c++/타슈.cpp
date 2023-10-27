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
    vector<int> goal(n);
    vector<int> curr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> goal[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> curr[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (goal[i] > curr[i])
        {
            ans += goal[i] - curr[i];
        }
    }
    cout << ans;
}
