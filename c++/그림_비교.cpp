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
    vector<vector<string>> art(N, vector<string>(5));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> art[i][j];
        }
    }
    int min_diff = 40;
    int a = 0;
    int b = 0;
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            int diff = 35;
            for (int k = 0; k < 5; k++)
            {
                for (int l = 0; l < 7; l++)
                {
                    if (art[j][k][l] == art[i][k][l])
                    {
                        diff -= 1;
                    }
                }
            }
            if (diff < min_diff)
            {
                min_diff = diff;
                a = i + 1;
                b = j + 1;
            }
        }
    }
    cout << a << " " << b;
}
