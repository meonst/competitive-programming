#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    cout << fixed << showpoint;
    cout << setprecision(8);
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    double ab, bc, cd;
    cin >> ab >> bc >> cd;
    double da = (ab * cd / bc);
    cout << da;
}
