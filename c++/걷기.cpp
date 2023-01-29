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
    long long home_x, home_y, time_1, time_2;
    cin >> home_x >> home_y >> time_1 >> time_2;
    if (time_1 * 2 < time_2)
    {
        cout << (home_x + home_y)  * time_1;
    }
    else if (time_1 > time_2)
    {
        cout << ((min(home_x, home_y) * time_2) + ((((max(home_x, home_y)- min(home_x, home_y)) / 2) * time_2) * 2) + (((max(home_x, home_y)- min(home_x, home_y)) % 2) * time_1));
    }
    else 
    {
        cout << ((min(home_x, home_y) * time_2) + ((max(home_x, home_y)- min(home_x, home_y)) * time_1));
    }
}
