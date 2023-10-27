#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> a(6);
    vector<int> b(6);

    for (int i = 0; i < 6; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < 6; i++)
    {
        cin >> b[i];
    }

    int winning = 0;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (a[i] > b[j]) winning += 1;
        }
    }

    int cd = gcd(winning, 36);
    cout << (winning / cd) << "/" << (36 / cd);

}
