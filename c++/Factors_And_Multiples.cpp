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
    int a, b;
    while (true) 
    {
        cin >> a >> b;
        if (!(a && b)) break;
        if (a < b) 
        {
            cout << (b % a == 0 ? "factor" : "neither") << "\n";
        }
        else if (a > b) 
        {
            cout << (a % b == 0 ? "multiple" : "neither") << "\n";
        }
    }
}
