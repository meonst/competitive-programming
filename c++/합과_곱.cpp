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
#include <cmath>
using namespace std;



int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    double sum, product;
    cin >> sum >> product;
    const double euler = 2.7182818284590452353;
    if (sum == product) cout << 1;
    // pow(sum/i, i) is biggest when i = sum / euler
    else if (pow(euler, sum / euler) < product) cout << -1;
    else
    {
        long double last = -1;
        for (int i = 2; ; i++)
        {
            long double now = pow(sum / i, i);
            //cout << i << ", " << now << "\n";
            if (now < last)
            {
                cout << -1;
                break;
            }

            if (now >= product)
            {
                cout << i;
                break;
            }
            last = now;
        }
    }
}
