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
    long long X, Y;
    cin >> X >> Y;
    long long Z = Y * 100 / X;
    if (Z >= 99)
    {
        cout << "-1";
    }
    else 
    {
        long long A = ((100 * Y) - X * Z - X) / (Z - 99);
        while ((Y + A) * 100 / (X + A) <= Z) A += 1;
        cout << A;
    }
}
