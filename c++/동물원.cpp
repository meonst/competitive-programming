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
    vector<vector<int>> p;
    p.push_back({1, 1, 1}); // no lion in line i, lion in left cage in line i, lion in right cage in line i;
    for (int i = 1; i <= N; i++)
    {
        vector<int> line = {
            (p[i - 1][0] + p[i - 1][1] + p[i - 1][2]) % 9901,
            (p[i - 1][0] + p[i - 1][2]) % 9901,
            (p[i - 1][0] + p[i - 1][1]) % 9901
            };
        p.push_back(line);
    };
    cout << p[N][0];
}
