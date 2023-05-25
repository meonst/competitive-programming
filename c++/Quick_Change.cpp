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
        int money;
        cin >> money;
        
        cout << money / 25 << " ";
        money %= 25;

        cout << money / 10 << " ";
        money %= 10;
        
        cout << money / 5 << " ";
        money %= 5;
        
        cout << money << "\n";
    }
}
