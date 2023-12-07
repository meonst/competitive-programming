#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int s, m, l;
    cin >> s >> m >> l;
    int score = 1 * s + 2 * m + 3 * l;
    cout << (score >= 10 ? "happy" : "sad");
}
