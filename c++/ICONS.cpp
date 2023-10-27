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
    int root = pow(n, 0.5);
    if (root * root >= n)
    {
        cout << root << " " << root;
    }
    else if ((root + 1) * root >= n)
    {
        cout << root + 1 << " " << root;
    }
    else if ((root + 1) * (root + 1) >= n)
    {
        cout << root + 1 << " " << root + 1;
    }
}
