#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int answer = 1;
    for (int i = 1; i <= n; i++)
    {
        answer *= i;
        answer %= 10;
    }
    cout << answer;
}
