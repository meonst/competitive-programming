#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while (true)
    {
        ll income;
        cin >> income;
        if (!income) break;
        if (income <= 1000000)
        {
        }
        else if (income <= 5000000)
        {
            income *= 0.9;
        }
        else
        {
            income *= 0.8;
        }
        cout << income << "\n";
    }
}
