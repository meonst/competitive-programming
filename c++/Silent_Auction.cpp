#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    string name;
    int price = -1;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string bidder;
        int bid;
        cin >> bidder >> bid;
        if (bid > price)
        {
            price = bid;
            name = bidder;
        }
    }
    cout << name;
}
