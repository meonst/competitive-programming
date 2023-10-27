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
    for (int i = 0; i < N; i++)
    {
        int sum;
        cin >> sum;
        cout << "Pairs for " << sum << ": ";
        bool first = true;
        for (int j = 1; j <= 12; j++)
        {
            for (int k = j + 1; k <= 12; k++)
            {
                if (j + k == sum)
                {
                    if (!first)
                    {
                        cout << ", ";
                    }
                    cout << j << " " << k;
                    first = false;
                }
            }
        }
        cout << "\n";
    }
}
