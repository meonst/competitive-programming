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

bool sort_by_second(pair<ll, ll> a, pair<ll, ll> b)
{
    if (a.second == b.second)
    {
        return a.first < b.first;
    }
    return (a.second < b.second);
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    vector<pair<ll, ll>> meetings(N, pair<ll, ll>());
    for (int i = 0; i < N; i++)
    {
        cin >> meetings[i].first >> meetings[i].second;
    }
    sort(meetings.begin(), meetings.end(), sort_by_second);
    ll answer = 0;
    ll last_end_time = 0;
    for (int i = 0; i < N; i++)
    {
        if (meetings[i].first >= last_end_time)
        {
            last_end_time = meetings[i].second;
            answer += 1;
        }
    }
    cout << answer;
    

}
