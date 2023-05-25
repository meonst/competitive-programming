#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int B = b * d;
    int A = a * d + b * c;
    int g = gcd(A, B);
    cout << A / g << " " << B / g;
}
