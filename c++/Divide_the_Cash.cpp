#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, d;
    cin >> n >> d;
    int total = 0;
    vector<int> solved(n);
    for (int i = 0; i < n; i++)
    {
        cin >> solved[i];
        total += solved[i];
    }
    int bounty = d / total;
    for (int i = 0; i < n; i++)
    {
        cout << bounty * solved[i] << "\n";
    }
}
