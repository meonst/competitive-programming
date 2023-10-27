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
    vector<int> shake(N + 1);
    
    shake[1] = 1;
    shake[2] = 2;
    shake[3] = 3;
    for (int i = 4; i < N + 1; i++)
    {
        shake[i] = (shake[i - 1] + shake[i - 2]) % 10;
    }
    cout << shake[N];

    
}
