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
    int minimum = 2100000000;
    vector<int> num(N);
    cin >> num[0];
    for (int i = 1; i < N; i++)
    {
        cin >> num[i];
        minimum = min(minimum, abs(num[i] - num[i - 1]));
    }
    cout << minimum;
}
