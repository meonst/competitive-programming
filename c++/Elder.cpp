#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    char owner;
    int n;
    cin >> owner >> n;
    vector<int> owner_history(26, 0);
    owner_history[owner - 65] = 1;
    for (int i = 0; i < n; i++)
    {
        char winner, loser;
        cin >> winner >> loser;
        if (loser == owner) 
        {
            owner = winner;
            owner_history[owner - 65] = 1;
        }
    }

    int sum = 0;

    for (int i = 0; i < 26; i++)
    {
        sum += owner_history[i];
    }

    cout << owner << "\n" << sum;
}
