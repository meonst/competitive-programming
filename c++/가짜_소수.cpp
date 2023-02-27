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
vector<ll> primes2;
ll mul(ll n, ll m, ll M){
	if( !m ) return 0;
	if( m&1 ) return (n + mul(n*2%M, m/2, M)) % M;
	else return mul(n*2%M, m/2, M);
}

ll pw(ll n, ll m, ll M){
	ll ans = 1;
	while(m){
		if( m%2 == 1 ) ans = mul(ans, n, M);
		n = mul(n, n, M); m /= 2;
	}
	return ans;
}

ll get_prime(ll n)
{
	for(int i = 2; i <= 500; i++){
        if (pw(i, n-1, n) != 1) return 1;
	}
	return 0;
}

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

int main()
{
    ll N = 1000000000;
    cout << "start\n";
    get_primes(N);
    cout << "primes1 done \n";
    ll count = 0;
    for (ll i = 2; i < N; i++)
    {
        if (get_prime(i) == 0)
        {
            if (primes[count + 95] != i) cout << i;
            count += 1;
        }
    }
    cout << "\ndone";
    cin.get();
}