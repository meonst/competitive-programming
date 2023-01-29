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
    long long W, p, q, n, first, sum, mod, j;
    cin >> W;
    for (int i = 0; i < W; i++)
    {
        cin >> p >> q >> n;
        // W = 100000; 
        // p = 1000000;
        // q = 954248;
        // n = 1000000;

        j = 2;
        p = (p > q) ? p % q : p;


        vector<long long> sums;
        sums.push_back(0);
        first = (p % q);
        sum = first;
        sums.push_back(sum);

        for (j; j <= n; j++)
        {
            mod = (mod + p) % q;
            if (first == mod)
                break;
            sum += mod;
            sums.push_back(sum);
        }

        sum *= (n / (j - 1));

        long long remainder = n % (j - 1);
        sum += sums[remainder];
        cout << sum << "\n";
    }
}
