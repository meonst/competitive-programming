#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int chicken, coke, beer;
    cin >> chicken >> coke >> beer;
    
    int m = min(chicken, coke / 2 + beer);
    cout << m;
    
}
