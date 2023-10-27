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
    int m = -1;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        m = max(m, a * b);
    }
    cout << m;
}
