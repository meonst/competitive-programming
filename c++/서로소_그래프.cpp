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
int euler_phi(int n)
{
    if (n == 1) return 0;
    int N = n;
    int i = 0;
    while (primes[i] <= n && i < primes.size())
    {
       // cout << "5: " << primes[i] << ", " << n << "\n";
        if (n % primes[i] == 0)
        {
            N = (N / primes[i]) * (primes[i] - 1);
            //cout << "0: " << n << ", " << primes[i] << ", " << N << "\n";
        }
        i += 1;
        
    }
    //cout << "1: " << n << ", " << N << "\n";

    return N;
}
int main()
{
    
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    get_primes(N);
    //cout << "2: " << primes.size() << "\n";
    int count = 0;
    for (int i = 1; i < N + 1; i++)
    {
        
        //cout << "3: " << i << ", " << euler_phi(i) << "\n";
        count += euler_phi(i);
    }
    cout << count;

}
