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
    while (true)
    {
        cin >> N;
        if (N == 0) break;

        ll max_area = 0;
        vector<vector<ll>> stack{{0, -1}};
        ll next_number;
        for (int i = 0; i < N; i++)
        {
            cin >> next_number;
            ll start = i;
            while (next_number < stack.back()[0])
            {
                max_area = max(max_area, stack.back()[0] * (i - stack.back()[1]));
                start = stack.back()[1];
                stack.pop_back();
            }
            if (next_number > stack.back()[0])
            {
                stack.push_back({next_number, start});
            }
        }

        while (0 < stack.back()[0])
        {
            max_area = max(max_area, stack.back()[0] * (N - stack.back()[1]));
            stack.pop_back();
        }
        cout << max_area << "\n";
    }
}
