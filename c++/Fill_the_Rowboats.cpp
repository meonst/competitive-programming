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
    for (int i = 1; i <= N; i++)
    {
        cout << i << " ";
        if (i % 6 == 0) cout << "Go! ";
    }
    if (N % 6 != 0) cout << "Go!";
}