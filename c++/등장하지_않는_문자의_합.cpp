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
        string s;
        cin >> s;
        int sum = 0;
        vector<bool> appeared(100, false);


        for (int j = 0; j < s.size(); j++)
        {
            appeared[s[j]] = true;
        }

        for (int j = 65; j < 91; j++)
        {
            if (!appeared[j]) sum += j;
        }
        cout << sum << "\n";

    }
}
