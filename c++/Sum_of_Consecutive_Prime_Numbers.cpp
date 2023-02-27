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


int N = 4000001;
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




int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    get_primes();

    int number_of_primes = 0;
    for (int i = 0; i < N; i++)
    {
        if (primes[i]) number_of_primes += 1;
    }

    vector<int> prime_sum(number_of_primes);
    int target;
    cin >> target;
    prime_sum[0] = 0;
    int position = 1;
    for (int i = 1; i < N; i++)
    {
        if (!primes[i]) continue;

        prime_sum[position] = prime_sum[position - 1] + i;
        position += 1;
    }

    int i = 1;
    int j = 1;
    int count = 0;

    while (prime_sum[j])
    {

        int sum = prime_sum[j] - prime_sum[i - 1];

        if (sum == target)
        {
            count += 1;
            j += 1;
        }
        else if (sum > target)
        {
            i += 1;
        }
        else j += 1;
    }
    cout << count;
}
