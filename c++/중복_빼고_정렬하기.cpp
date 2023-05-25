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
    vector<int> num(N);
    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
    }
    sort(num.begin(), num.end());

    int prev = -1001;
    for (int i = 0; i < N; i++)
    {
        if (num[i] != prev)
        {
            prev = num[i];
            cout << num[i] << " ";
        }
    }
}
