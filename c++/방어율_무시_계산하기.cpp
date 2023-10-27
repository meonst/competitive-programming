#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << fixed << showpoint;
    cout << setprecision(7);
    int n;
    cin >> n;
    double ignore_defense = 0;
    for (int i = 0; i < n; i++)
    {
        double ignore;
        cin >> ignore;
        ignore /= 100;
        ignore_defense = (1 - (1 - ignore_defense / 100) * (1 - ignore)) * 100;
        cout << ignore_defense << " ";
    }
}
