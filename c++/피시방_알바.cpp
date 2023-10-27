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
    int rejected = 0;
    vector<bool> seats(101, false);
    for (int i = 0; i < N; i++)
    {
        int seat;
        cin >> seat;
        if (seats[seat]) 
        {
            rejected += 1;
        }
        seats[seat] = true;
    }
    cout << rejected;
}
