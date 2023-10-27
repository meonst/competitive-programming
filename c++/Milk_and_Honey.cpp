#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int milk, honey, n;
    int sum = 0;

    cin >> milk >> honey >> n;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        sum += max(a * milk, b * honey);
    }
    cout << sum;
}
