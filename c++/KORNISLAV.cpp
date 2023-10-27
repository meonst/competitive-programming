#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cout << fixed << showpoint;
    cout << setprecision(1);

    vector<int> length(4);
    cin >> length[0] >> length[1] >> length[2] >> length[3];

    sort(length.begin(), length.end());
    
    cout << length[0] * length[2];
    
}
