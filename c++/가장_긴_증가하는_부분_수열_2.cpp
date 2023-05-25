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


vector<ll> input(1000000);
vector<ll> max_containing(1000000, -1);
ll get_max_containing(int here)
{

    if (max_containing[here] == -1)
    {
        ll longest = 1;
        for (int i = 0; i < here; i++)
        {
            if (input[i] < input[here])
                longest = max(longest, get_max_containing(i) + 1);
        }
        max_containing[here] = longest;
    }
    return max_containing[here];
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    ll longest = -1;
    for (ll i = 0; i < n; i++)
    {
        cin >> input[i];
        //cout << i << ", " << get_max_containing(i) << "\n";
        longest = max(get_max_containing(i), longest);
    }
    cout << longest;
}
