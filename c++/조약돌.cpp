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
#include <stdio.h>
#include <stdlib.h>
#include <cassert>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll N;
    cin >> N;
    ll a = sqrt(N) + 1;
    ll b = sqrt(N) + 1;
    ll out;
    if ((a - 1) * (b - 1) >= N)
    {
        out = a * 4 - 8, 4;
    }
    else if (a * (b - 1) >= N)
    {
        out = a * 4 - 6;
    }
    else if (a * b >= N)
    {
        out = a * 4 - 4;
    }
    else if (a * (b + 1) >= N)
    {
        out = a * 4 - 2;
    }
    else if ((a + 1) * (b + 1) >= N)
    {
        out = a * 4;
    }
    if (out < 4) out = 4;
    cout << out;
    
}
