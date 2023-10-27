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
    ll modulo;
    cin >> modulo;
    ll remainder;
    bool negative = false;

    stack<int> a;
    if (n < 0 && modulo > 0)
    {
        negative = true;
        n = abs(n);
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
    }
    else
    {
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
    }
    if (a.empty())
    {
        cout << 0;
    }
    else
    {
        if (negative) cout << "-";
    }
    
    while (!a.empty())
    {
        cout << a.top();
        a.pop();
    }

}

