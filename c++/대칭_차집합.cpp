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
using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long A;
    long long B;
    map<int, bool> set;
    cin >> A >> B;
    long long sum = A + B;
    long long in;
    for (long i = 0; i < A; i++)
    {
        cin >> in;
        set.insert({in, true});
    }
    for (long i = 0; i < B; i++)
    {
        cin >> in;
        if (set[in]) 
        {
            sum -= 2;
        }
    }
    cout << sum;
}
