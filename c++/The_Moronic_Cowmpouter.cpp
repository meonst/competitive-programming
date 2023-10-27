#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    ll modulo = -2;
    ll remainder;
    stack<int> a;
    while (n != 0)
    {
        remainder = n % modulo;
        if (remainder < 0)
        {
            remainder += abs(modulo);
            n = (n / modulo) + 1;
        }
        else
        {
            n /= modulo;
        }

        a.push(remainder);

    }

    if (a.empty())
    {
        cout << 0;
    }
    
    while (!a.empty())
    {
        cout << a.top();
        a.pop();
    }

}

