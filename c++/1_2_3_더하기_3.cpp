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

vector<long long> ways;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long T, n;
    cin >> T;
    ways.push_back(0);
    ways.push_back(1);
    ways.push_back(2);
    ways.push_back(4);
    
    //cout << ways.size();
    for (long long i = 0; i < T; i++)
    {
        cin >> n;
        if (n < ways.size())
        {
            cout << ways[n] << "\n";
            continue;
        }
        long long j = ways.size();
        for (j; j <= n; j++)
        {
            ways.push_back((ways[j - 1] + ways[j - 2] + ways[j - 3]) % 1000000009);
        }
        cout << ways[n] << "\n";

    }
}
