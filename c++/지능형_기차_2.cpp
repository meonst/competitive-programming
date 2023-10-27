#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int now = 0;
    int maxi = -1;
    int out, in;
    for (int i = 0; i < 10; i++)
    {
        cin >> out >> in;
        now += in - out;
        maxi = max(maxi, now);
    }
    cout << maxi;
}
