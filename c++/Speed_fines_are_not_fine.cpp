#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int limit, speed;
    cin >> limit >> speed;
    int diff = speed - limit;
    if (diff <= 0)
    {
        cout << "Congratulations, you are within the speed limit!";
    }
    else
    {
        if (diff <= 20)
            cout << "You are speeding and your fine is $100.";
        else if (diff <= 30)
            cout << "You are speeding and your fine is $270.";
        else if (diff >= 31)
            cout << "You are speeding and your fine is $500.";
    }
}
