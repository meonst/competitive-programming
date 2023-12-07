#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll a, b;
    cin >> a >> b;
    ll field = a * b;
    ll answer = field / 24200;
    ll remainder = field % 24200;
    if (remainder != 0) answer += 1;
    

    cout << answer;
}
