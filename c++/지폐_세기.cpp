#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    int sum = 0;
    for (int i = 0; i < t; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a == 136 || b == 136) sum += 1000;
        if (a == 142 || b == 142) sum += 5000;
        if (a == 148 || b == 148) sum += 10000;
        if (a == 154 || b == 154) sum += 50000;
    }
    cout << sum;
}
