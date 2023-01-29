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
    int egg_count, customer_count;
    cin >> egg_count >> customer_count;
    vector<int> customer_bid(customer_count, 0);
    for (int i = 0; i < customer_count; i++)
    {
        cin >> customer_bid[i];
    }
    sort(customer_bid.begin(), customer_bid.end());

    int sum = 0;
    int price;
    for (int i = 0; i < customer_count; i++)
    {
        if (sum < min(customer_count - i, egg_count) * customer_bid[i])
        {
            sum = min(customer_count - i, egg_count) * customer_bid[i];
            price = customer_bid[i];
        }
        //cout << customers[i] << " ";
    }
    cout << price << " " << sum;

}
