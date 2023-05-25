#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    vector<vector<int>> (N - 1);
    for (int i = 0; i < N - 1; i++)
    {
        cin >> edges[i].first >> edges[i].second;
        cout << edges[i].first << ", " << edges[i].second << "\n";
    }
}
