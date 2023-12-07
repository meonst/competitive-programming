#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, x, b, y, T;
    cin >> a >> x >> b >> y >> T;
    int first = a + max(0, T - 30) * x * 21;
    int second = b + max(0, T - 45) * y * 21;
    cout << first << " " << second;
}
