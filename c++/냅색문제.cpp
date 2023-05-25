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

vector<ll> first_half_sum, second_half_sum;
vector<ll> n(30);

void first_dfs(ll start, int end, ll sum)
{
    if (start > end)
    {
        first_half_sum.push_back(sum);
        return;    
    }
    first_dfs(start + 1, end, sum);
    first_dfs(start + 1, end, sum + n[start]);
}

void second_dfs(ll start, int end, ll sum)
{
    if (start > end)
    {
        second_half_sum.push_back(sum);
        return;
    }
    second_dfs(start + 1, end, sum);
    second_dfs(start + 1, end, sum + n[start]);
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll N, C;
    cin >> N >> C;
    for (ll i = 0; i < N; i++)
    {
        cin >> n[i];
    }
    first_dfs(0, N / 2 - 1, 0);
    second_dfs(N / 2, N - 1, 0);
    sort(second_half_sum.begin(), second_half_sum.end());


    // for (ll i = 0; i < first_half_sum.size(); i++)
    // {
    //     cout << first_half_sum[i] << " ";
    // }
    // cout << "\n";
    // for (ll i = 0; i < second_half_sum.size(); i++)
    // {
    //     cout << second_half_sum[i] << " ";
    // }
    // cout << "\n";


    ll count = 0;
    for (ll i = 0; i < first_half_sum.size(); i++)
    {
        ll start = 0;
        ll end = second_half_sum.size() - 1;
        ll cutline = C - first_half_sum[i];

        if (second_half_sum[0] > cutline) continue;

        for (int j = 0; j < 30; j++)
        {
            ll half = (start + end) / 2;
            if (second_half_sum[half] <= cutline)
            {
                start = half;
            }
            else
            {
                end = half;
            }
        }
        //cout << second_half_sum[start] << ", " << second_half_sum[end] << ", " << cutline << ", " << end << "\n";
        count += ((second_half_sum[end] > cutline) ? start : end) + 1;
    }
    cout << count;
}
