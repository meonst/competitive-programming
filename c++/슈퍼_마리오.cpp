#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int sum = 0;
    int smallest_difference = 100;
    int target = 0;
    for (int i = 0; i < 10; i++)
    {
        int num;
        cin >> num;
        sum += num;
        if (abs(100 - sum) <= smallest_difference)
        {
            target = sum;
            smallest_difference = abs(100 - sum);
        }
    }
    cout << target;
}

