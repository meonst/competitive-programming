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
using namespace std;
typedef long long ll;

ll mod, p;


ll mod_power(ll r, ll n)
{
    // this returns (r ^ n) % mod
    if (n == 0) return 1;
    else if (n == 1) return r;
    else if (n % 2 == 0)
    {
        p = mod_power(r, n / 2);
        return (p * p) % mod;
    }
    else 
    {
        p = mod_power(r, (n - 1) / 2);
        return ((p * p) % mod * r) % mod;
    }
}   
ll sum_until(ll r, ll n)
{
    // this returns r + r ^ 2 + ... + r ^ n
    
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return r;
    }
    else if (n == 2)
    {
        return (r % mod + (r * r) % mod) % mod;
    }
    else if (n % 2 == 0)
    {
        return (sum_until(r, n / 2) * (1 + mod_power(r, n / 2))) % mod;
    }
    else
    {
        return ((sum_until(r, (n - 1) / 2) * (1 + mod_power(r, (n - 1) / 2))) % mod + mod_power(r, n)) % mod;
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll first, r, n;
    cin >> first >> r >> n >> mod;
    first %= mod;
    r %= mod;
    cout << (first * (1 + sum_until(r, n - 1))) % mod;
}
