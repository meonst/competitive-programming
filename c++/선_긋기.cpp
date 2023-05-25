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
#include <regex>
#include <stdio.h>
#include <stdlib.h>
#include <cassert>
#include <queue>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    vector<vector<int>> lines(N, vector<int>(2));
    for (int i = 0; i < N; i++)
    {
        cin >> lines[i][0] >> lines[i][1];
    }
    sort(lines.begin(), lines.end());
    int length = 0;

    int start = lines[0][0];
    int end = lines[0][1];
    for (int i = 1; i < N; i++)
    {
        if (lines[i][0] > end)
        {
            length += end - start;
            start = lines[i][0];
            end = lines[i][1];
        }
        else
        {
            if (lines[i][1] <= end) continue;
            else end = lines[i][1];
        }
    }
    length += end - start;
    cout << length;
}
