#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int answer;
    cin >> answer;
    int count = 0;
    for (int i = 0; i < 5; i++)
    {
        int reply;
        cin >> reply;
        if (reply == answer) count++;
    }
    cout << count;
}
