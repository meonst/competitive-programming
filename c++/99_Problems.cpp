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

    int diff = 99999999;
    int price = 0;

    for (int i = 99; i < 11000; i += 100)
    {
        if (diff >= abs(i - n))
        {
            diff = abs(i - n);
            price = i;
        }
    }
    cout << price;
}
