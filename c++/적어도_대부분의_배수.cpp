#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> num(5);
    for (int i = 0; i < 5; i++) cin >> num[i];
    int answer = 1;
    while (true)
    {
        int count = 0;
        for (int j = 0; j < 5; j++)
        {
            if (answer % num[j] == 0) count += 1;
        }
        if (count >= 3) break;
        answer += 1;
    }
    cout << answer;
}
