#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int P;
    cin >> P;
    for (int i = 0; i < P; i++)
    {
        int T;
        cin >> T;
        cout << T << " ";
        vector<int> students(20);
        int c = 0;
        for (int j = 0; j < 20; j++)
        {
            cin >> students[j];
            for (int k = 0; k < j; k++)
            {
                c += students[k] > students[j] ? 1 : 0;
            }
        }
        cout << c << "\n";

    }
}
