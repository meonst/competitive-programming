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
    double defense = a * (100 - b) / 100;
    // cout << defense << "\n";
    cout << (defense >= 100 ? 0 : 1);
}
