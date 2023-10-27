#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b;
    cin >> a >> b;
    a -= 1;
    b -= 1;
    int aq = a / 4;
    int bq = b / 4;

    int ar = a % 4;
    int br = b % 4;

    int x = abs(aq - bq) + abs(ar - br);
    cout << x;
}
