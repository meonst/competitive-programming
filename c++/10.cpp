#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a;
    cin >> a;
    ll answer = 6;
    for (int i = 11; i <= a; i++)
    {
        answer *= i;
    }
    cout << answer;
}
