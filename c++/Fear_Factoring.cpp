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


unsigned long long sum_of_factors(unsigned long long n)
{
    unsigned long long sum = 0;
    unsigned long long i = 1;
    unsigned long long j;
    unsigned long long quotient;
    for (i; i <= n; i = j + 1)
    {
        // quotient = how many times i appears as a factor
        quotient = n / i;
        // j = biggest number that appears the same times as i
        // n = quotient * j + remainder
        j = n / quotient;
        // add i ~ j and they all appear 'quotient' times
        sum += ((i + j) * (j - i + 1) / 2) * quotient;
    }
    
    //cout << "1: " << n << ", " << sum << "\n";
    return sum;
}


int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    unsigned long long a, b;
    cin >> a >> b;
    cout << sum_of_factors(b) - sum_of_factors(a - 1);
}


