#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string a, b;
    cin >> a >> b;
    int answer = 1;
    if (a[0] != b[0]) answer *= 2;
    if (a[1] != b[1]) answer *= 2;
    if (a[2] != b[2]) answer *= 2;
    if (a[3] != b[3]) answer *= 2;
    cout << answer;
}
