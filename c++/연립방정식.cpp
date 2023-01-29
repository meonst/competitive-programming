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
    int n, diff;
    int quotient = 1000000007;
    cin >> n;
    
    vector<int> a(n);
    vector<long long> x(n, 1);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            diff = a[i] - a[j];
            if (!diff)
            {
                cout << "NO";
                return 0;
            }
            x[i] *= diff;
            x[i] %= quotient;
            x[j] *= -1 * diff;
            x[j] %= quotient;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << (x[i] + quotient) % quotient << " ";
    }
    

}
