#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string X;
    cin >> X;
    int c = 0;
    string divided_by_three;
    while (true)
    {
        if (X.size() == 1) break;

        int sum = 0;
        for (int i = 0; i < X.size(); i++)
        {
            sum += X[i] - 48;
        }
        
        c += 1;
        X = to_string(sum);
    }
    cout << c << "\n";
    cout << ((X[0] - 48) % 3 == 0 ? "YES" : "NO");

}
