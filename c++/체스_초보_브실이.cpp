#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> score(130);
    int s = 0;

    score['.'] = 0;

    score['K'] = 0;
    score['k'] = 0;

    score['P'] = 1;
    score['p'] = -1;

    score['N'] = 3;
    score['n'] = -3;

    score['B'] = 3;
    score['b'] = -3;

    score['R'] = 5;
    score['r'] = -5;

    score['Q'] = 9;
    score['q'] = -9;

    for (int i = 0; i < 8; i++)
    {
        string row;
        cin >> row;

        for (int j = 0; j < 8; j++)
        {
            s += score[row[j]];
        }
    }
    cout << s;
}
 