#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, friend_count;
    cin >> n >> friend_count;
    vector<int> order(n);
    vector<bool> friends(n, false);

    for (int i = 0; i < n; i++)
    {
        cin >> order[i];
    }
    for (int i = 0; i < friend_count; i++)
    {
        int a;
        cin >> a;
        friends[a - 1] = true;
    }

    int c = 0;
    for (int i = 0; i < friend_count; i++)
    {
        if (!friends[order[i] - 1]) c += 1;
    }
    cout << c;
}
