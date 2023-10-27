#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, price, diff;
    cin >> n >> price;
    for (int i = 1; i < n; i++)
    {
        cin >> diff;
        price += diff;
    }
    cout << price;
}
