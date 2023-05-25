#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        ll a;
        cin >> a;
        bool good = true;
        for (int j = 2; j <= 1000000; j++)
        {
            if (a % j == 0)
            {
                good = false;
            }
        }
        cout << (good ? "YES\n" : "NO\n");
    }
}
