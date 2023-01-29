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

vector<int> primes;
int first_prime, second_prime;

void get_primes(int N)
{
    primes.push_back(2);
    
    for (int i = 3; i < N; i++)
    {
        bool prime = true;
        for (int j = 0; j < primes.size(); j++)
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
bool is_prime(int N)
{
    int i = 1;
    int size = primes.size();
    
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
void goldbach(int N)
{
    for (int i = 0; i < primes.size(); i++)
    {
        if (is_prime(N - primes[i]))
        {
            first_prime = primes[i];
            second_prime = N - primes[i];
            break;
        }
    }
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    get_primes(1000000);
    while (true)
    {
        cin >> N;
        goldbach(N);
        cout << first_prime << " " << second_prime;
    }
}
