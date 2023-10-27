#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int chicken, t1, t2, t3;
    cin >> chicken >> t1 >> t2 >> t3;

    int sum = 0;

    sum += min(chicken, t1);
    sum += min(chicken, t2);
    sum += min(chicken, t3);

    cout << sum;
}
