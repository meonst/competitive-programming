#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int X, Y;
    cin >> X >> Y;

    while (X <= Y)
    {
        cout << "All positions change in year " << X << "\n";
        X += 60;
    }
}
