#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int S, M;
    
    cin >> S >> M;
    S -= 1023;
    if (S <= 0)
    {
        cout << "No thanks";
    }
    else
    {
        bool possible = true;
        for (int a = 1024; a >= 1; a /= 2)
        {
            bool sub_S = false;
            bool sub_M = false;
            if (S >= a)
            {
                S -= a;
                sub_S = true;
            }
            if (M >= a)
            {
                M -= a;
                sub_M = true;
            }
            //cout << a << ", " << sub_S << ", " << sub_M << "\n";
            if (sub_S && !sub_M)
            {
                possible = false;
            }
        }
        cout << (possible ? "Thanks" : "Impossible");

    }
    
 
}
