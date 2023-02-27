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
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long X, Y;
    cin >> X >> Y;
    long long diff = Y - X;
    if (diff == 0)
    {
        cout << 0;
        return 0;
    }
    long long n = pow(diff, 0.5);
    if (n * n - n >= diff) cout << 2 * n - 2;
    else if (n * n >= diff) cout << 2 * n - 1;
    else if (n * n + n >= diff) cout << 2 * n;
    else if (n * n + 2 * n + 1 >= diff) cout << 2 * n + 1;
    
    //              n ^ 2 - 2n + 1 = 2n - 3 days
    //n * (n - 1) = n ^ 2 - n      = 2n - 2 days
    //n * (n - 1) + n = n ^ 2      = 2n - 1 days

}
