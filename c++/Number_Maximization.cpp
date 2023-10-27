#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string a;
    cin >> a;

    vector<char> chars(a.size());

    for (int i = 0; i < a.size(); i++)
    {
        chars[i] = a[i];
    }
    sort(chars.begin(), chars.end());
    for (int i = chars.size() - 1; i >= 0; i--)
    {
        cout << chars[i];
    }
}
