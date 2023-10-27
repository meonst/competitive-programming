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
    for (int i = 0; i < 5; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < N; j++)
            {
                for (int k = 0; k < 5 * N; k++)
                {
                    cout << "@";
                }
                cout << "\n";
            }
        }
        else
        {
            for (int j = 0; j < N; j++)
            {
                for (int k = 0; k < N; k++)
                {
                    cout << "@";
                }
                cout << "\n";
            }
        }
    }
}
