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
    int cuteness = 0;
    
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        cuteness += (a ? 1 : -1);
    }
    cout << (cuteness > 0 ? "Junhee is cute!" : "Junhee is not cute!");
}
