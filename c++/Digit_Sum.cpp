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

long long sum(long long n)
{
    vector<long long> numbers(10, 0);
    long long small_divide, big_divide, quotient, big_remainder, small_remainder;
    for (int i = 0; pow(10, i) <= n; i++)
    {
        small_divide = pow(10, i);
        big_divide = small_divide * 10;
        for (int j = 1; j < 10; j++)
        {
            quotient = n / big_divide;
            big_remainder = n % big_divide;
            if (big_remainder >= j * small_divide)
            {

                if (big_remainder < (j + 1) * small_divide)
                {
                    small_remainder = n % small_divide;
                    numbers[j] += small_remainder + 1;
                }
                else
                {
                    numbers[j] += small_divide;
                }
            }
            numbers[j] += quotient * small_divide;
        }
    }

    long long s = 0;
    for (int i = 1; i < 10; i++)
    {
        s += numbers[i] * i;
    }
    return s;
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int cases;
    cin >> cases;
    long long a, b;
    for (int i = 0; i < cases; i++)
    {
        cin >> a >> b;
        if (a == 0)
            a = 1;

        cout << sum(b) - sum(a - 1) << "\n";
    }
}
