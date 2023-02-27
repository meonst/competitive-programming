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
void get_primes(int N)
{
    primes.push_back(2);
    
    for (int i = 3; i <= N; i++)
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
bool is_palindrome(int N)
{
    string A = to_string(N);
    int length = A.length();
    for (int i = 0; i < length / 2; i++) 
    {
        if (A[i] != A[length - i - 1]) return false;
    }
    return true;
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    get_primes(1300031);
    for (int i = 0; ; i++)
    {
        if (primes[i] < N) continue;
        if (is_palindrome(primes[i]))
        {
            cout << primes[i];
            break;
        }
    }
}
