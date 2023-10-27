#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b, n;
    cin >> a >> b >> n;
    for (int i = 1; i <= n; i++)
    {
        if (i % a == 0)
        {
            if (i % b == 0)
            {
                cout << "FizzBuzz\n";
            }
            else
            {
                cout << "Fizz\n";
            }
        }
        else
        {
            if (i % b == 0)
            {
                cout << "Buzz\n";
            }
            else
            {
                cout << i << "\n";
            }
        }

    }
}
