#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string a;
    cin >> a;
    bool hiss = false;
    for (int i = 1; i < a.size(); i++)
    {
        if (a[i] == 's' && a[i - 1] == 's') hiss = true;
    }
    cout << (hiss ? "hiss" : "no hiss");
}
