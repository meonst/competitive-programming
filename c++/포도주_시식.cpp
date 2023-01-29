
#include <string>
#include <iomanip>
#include <utility>
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <stdint.h>
#include <inttypes.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <unordered_map>
#include <numeric>
#include <algorithm>
using namespace std;
vector<vector<long>> score(10001, vector<long>(3, -1));
vector<long> stairs(10001, 0);

long get_score(int n, int consecutive)
{
    if (consecutive == 1)
    {
        if (score[n][consecutive] == -1)
        {
            score[n][consecutive] = max(max(get_score(n - 2, 1), get_score(n - 2, 2)), max(get_score(n - 3, 1), get_score(n - 3, 2))) + stairs[n];
        }
    }
    if (consecutive == 2)
    {
        if (score[n][consecutive] == -1)
        {
            score[n][consecutive] = get_score(n - 1, 1) + stairs[n];
        }
    }
    return score[n][consecutive];
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int s;
    cin >> s;
    for (int i = 1; i <= s; i++)
    {
        cin >> stairs[i];
    }
    score[1][1] = stairs[1];
    score[1][2] = 0;
    score[2][1] = stairs[2];
    score[2][2] = stairs[1] + stairs[2];
    score[3][1] = stairs[1] + stairs[3];
    score[3][2] = stairs[2] + stairs[3];
    if (s == 1) cout << stairs[1];
    else if (s == 2) cout << stairs[1] + stairs[2];
    else cout << max(max(get_score(s, 1), get_score(s, 2)), max(get_score(s - 1, 1), get_score(s - 1, 2)));
}
