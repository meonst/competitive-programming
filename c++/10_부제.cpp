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
    int c = 0;
    for (int i = 0; i < 5; i++)
    {
        int b;
        cin >> b;
        if (a == b) c++;
    }
    cout << c;
}
