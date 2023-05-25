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
ll modulo = 1000000007;

ll remainder(ll n)
{
    n %= modulo;
    if (n < 0) n += modulo;
    return n;
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    vector<ll> scoville(N);
    for (int i = 0; i < N; i++)
    {
        cin >> scoville[i];
    }

    sort(scoville.begin(), scoville.end());

    for (int i = 1; i < N; i++)
    {
        scoville[i] += scoville[i - 1];
        scoville[i] %= modulo;
    }


    ll multiplier = 1;
    ll sum = 0;
    for (int i = 0; i < N - 1; i++)
    {
        sum += (scoville[N - 1] - scoville[N - 2 - i] - scoville[i]) * multiplier;
        sum = remainder(sum);
        multiplier = (multiplier * 2) % modulo;
    }
    cout << sum;
    
}
