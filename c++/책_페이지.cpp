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

int main()
{
    ios_base ::sync_with_stdio(false);
    
    cin.tie(NULL);
    cout.tie(NULL);
    long long pages;
    cin >> pages;
    vector<long long> numbers(10, 0);
    long long small_divide, big_divide, quotient, big_remainder, small_remainder;
    for (int i = 0; pow(10, i) <= pages; i++)
    {
        small_divide = pow(10, i);
        big_divide = small_divide * 10;
        // cout << "0, " << i << ", " << pages - small_divide + 1 << "\n"; 
        numbers[0] += pages - small_divide + 1;
        for (int j = 1; j < 10; j++)
        {
            quotient = pages / big_divide;
            big_remainder = pages % big_divide;
            if (big_remainder >= j * small_divide)
            {
                 
                if (big_remainder < (j + 1) * small_divide)
                {
                    small_remainder = pages % small_divide;
                    numbers[j] += small_remainder + 1;
                }
                else
                {
                   numbers[j] += small_divide;
                }    
            }
            numbers[j] += quotient * small_divide;
        }
    /*
    1 every 10 
    10 every 100
    100 every 1000
    1000 every 10000
    */
    }
    // cout << "all, " << numbers[0] << "\n";
    for (int i = 1; i < 10; i++) 
    {
        numbers[0] -= numbers[i];
        // cout << i << ", minus, " << numbers[0] << "\n";
    }
    for (int i = 0; i < 10; i++)
    {
        cout << numbers[i] << " ";
    }
}
