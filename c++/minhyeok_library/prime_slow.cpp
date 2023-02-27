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
vector<ll> primes;

#pragma region 이름은 몰라요
void get_primes(ll N)
{
    primes.push_back(2);
    
    for (ll i = 3; i < N; i++)
    {
        bool prime = true;
        for (ll j = 0; j < primes.size(); j++)
        {
            if (primes[j] > sqrt(i)) break;

            if (i % primes[j] == 0)
            {
                prime = false;
                break;
            }
        }
        if (prime) primes.push_back(i);
    }
}
bool is_prime(ll N)
{
    ll i = 1;
    ll size = primes.size();
    
    while (primes[size - i] >= N)
    {
        if (primes[size - i] == N) 
        {
            return true;
        }
        i++;
    }
    return false;
}
#pragma endregion

#pragma region 에라토스테네스의 체
int N = 40000001;
vector<int> primes(N, 1);
void get_primes()
{
    primes[0] = 0;
    primes[1] = 0;
    for (int i = 2; i < N; i++)
    {
        if (!primes[i]) continue;
        
        int not_prime = 2 * i;

        while (not_prime <= N - 1)
        {
            primes[not_prime] = 0;
            not_prime += i;
        }
    }
    
}
#pragma endregion
