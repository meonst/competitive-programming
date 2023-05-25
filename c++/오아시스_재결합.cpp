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
    ll N;
    cin >> N;
    vector<vector<int>> line{};
    ll count = 0;
    for (ll i = 0; i < N; i++)
    {
        int next_person;
        cin >> next_person;
        int duplicate = 1;
        while (line.size() > 0 && next_person >= line.back()[0])
        {
            count += line.back()[1];
            //cout << "1: " << i << ", " << next_person << ", " << line.back()[0] << ", " << line.back()[1] << "\n";
            if (next_person == line.back()[0])
            {
                duplicate = line.back()[1] + 1;
            }
            line.pop_back();
        }

        if (line.size() > 0)
        {
            count += 1;
            //cout << "2: " << i << ", " << next_person << ", " << line.back()[0] << ", " << line.back()[1] << "\n";
        }

        line.push_back(vector<int>{next_person, duplicate});
    }
    cout << count;
}
