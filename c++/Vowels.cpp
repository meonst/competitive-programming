#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while (true)
    {
        string a;
        getline(cin, a);
        if (a == "#") break;
        int sum = 0;
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] == 97) sum += 1;
            if (a[i] == 101) sum += 1;
            if (a[i] == 105) sum += 1;
            if (a[i] == 111) sum += 1;
            if (a[i] == 117) sum += 1;

            if (a[i] == 65) sum += 1;
            if (a[i] == 69) sum += 1;
            if (a[i] == 73) sum += 1;
            if (a[i] == 79) sum += 1;
            if (a[i] == 85) sum += 1;
        }
        cout << sum << "\n";
    }
}
