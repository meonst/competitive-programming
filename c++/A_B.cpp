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
    ll A, B;
    cin >> A >> B;
    vector<ll> list {A};
    int count = 1;
    bool done = false;
    while (list.size() > 0)
    {
        vector<ll> new_list;
        count += 1;
        for (int i = 0; i < list.size(); i++)
        {
            ll first = list[i] * 2;
            ll second = list[i] * 10 + 1;

            if (first < B) new_list.push_back(first);
            if (second < B) new_list.push_back(second);

            if (first == B)
            {
                done = true;
            }
            if (second == B)
            {
                done = true;
            }
        }
        if (done) break;
        list = new_list;
    }
    cout << (done ? count : -1);
}
