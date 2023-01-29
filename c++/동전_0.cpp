
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
    int a, price;
    cin >> a >> price;
    vector<int> coins(a, 0);
    for (int i = 0; i < a; i++)
    {
        cin >> coins[i];
    }
    int c = 0;
    int coin = a - 1;
    while (price > 0)
    {
        if (price >= coins[coin])
        {
            price -= coins[coin];
            c += 1;
        }
        else 
        {
            coin -= 1;
        }
    }
    cout << c;
}
