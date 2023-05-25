#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<vector<int>> plane(103, vector<int>(103, 0));
    for (int i = 0; i < 4; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        for (int j = a; j < c; j++)
        {
            for (int k = b; k < d; k++)
            {
                plane[j][k] = 1;
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < 103; i++)
    {
        for (int j = 0; j < 103; j++)
        {
            sum += plane[i][j];
        }
    }
    cout << sum;

}
