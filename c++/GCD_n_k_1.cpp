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
using namespace std;

vector<long long> primes;
void get_primes(long long N)
{
    primes.push_back(2);
    
    for (long long i = 3; i < N; i++)
    {
        bool prime = true;
        for (long long j = 0; j < primes.size(); j++)
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
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long n;
    cin >> n;
    if (n == 1)
    {
        cout << 1;
        return 0;
    }
    get_primes(1000000);
    //cout << primes.size() << "\n";
    long long count = n;
    long long n_divide = n;
    bool is_prime = true;

    for (long long i = 0; i < primes.size(); i++)
    {
        if (n_divide % primes[i] == 0)
        {
            while (n_divide % primes[i] == 0) n_divide /= primes[i];
            //cout << "1: " << primes[i] << "\n";
            is_prime = false;
            count -= count / primes[i];
        }
    }
    //cout << "2: " << n_divide << "\n";



    if (is_prime)
    {
        count -= 1;
    }
    else if (n_divide != 1)
    {
        count -= count / n_divide;
    }
    cout << count;
}
