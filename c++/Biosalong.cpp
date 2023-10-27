#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string seats;
    int n;
    cin >> n >> seats;
    
    int a = -1;
    int b = -1;
    for (int i = 0; i < n; i++)
    {
        if (seats[i] == '.')
        {
            if (a == -1)
            {
                a = i;
            }
            else
            {
                b = i;
                break;
            }
        }
    }
    int mini = b - a - 1;

    for (int i = b + 1; i < n; i++)
    {
        //cout << a << ", " << b << "\n";
        if (seats[i] == '.')
        {
            a = b;
            b = i;
            if (mini > (b - a - 1))
            {
                mini = b - a - 1;
            }
        }
    }
    //cout << a << ", " << b << "\n";
    cout << mini;

}
