#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int packages, collisions;
    cin >> packages >> collisions;
    int score = 50 * packages - 10 * collisions + (packages > collisions ? 500 : 0);
    cout << score;
}
