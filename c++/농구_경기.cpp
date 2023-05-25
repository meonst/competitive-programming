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
    vector<int> names(26, 0);
    for (int i = 0; i < N; i++)
    {
        string name;
        cin >> name;
        names[name[0] - 97] += 1;
    }
    bool forfeit = true;
    for (int i = 0; i < 26; i++)
    {
        char first = i + 97;
        //cout << first << ": " << names[i] << "\n";
        if (names[i] >= 5)
        {
            forfeit = false;
            cout << first;
        }
    }
    if (forfeit) cout << "PREDAJA";
}
