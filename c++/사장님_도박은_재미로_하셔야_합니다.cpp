#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a;
    int sum = 0;
    while (true)
    {
        cin >> a;
        if (a == -1) break;
        sum += a;
    }
    cout << sum;
}
