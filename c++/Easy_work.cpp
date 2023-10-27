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
    map<string, bool, greater<string>> names;

    for (int i = 0; i < N; i++)
    {
        string name, status;
        cin >> name >> status;
        if (status[0] == 'e')
        {
            names[name] = true;
        }
        else
        {
            names[name] = false;
        }
    }
    for (auto name = names.begin(); name != names.end(); name++)
    {
        if (name -> second) cout << name -> first << "\n";
    }
    
}
