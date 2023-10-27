#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> W(10);
    vector<int> K(10);
    for (int i = 0; i < 10; i++)
    {
        cin >> W[i];
    }
    for (int i = 0; i < 10; i++)
    {
        cin >> K[i];
    }
    sort(W.begin(), W.end());
    sort(K.begin(), K.end());
    cout << (W[7] + W[8] + W[9]) << " " << (K[7] + K[8] + K[9]);
}
