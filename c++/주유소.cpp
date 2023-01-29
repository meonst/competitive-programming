
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
    long long N;
    cin >> N;
    vector<long long> oil(N, 0);
    vector<long long> distance(N - 1, 0);
    for (long long i = 0; i < N - 1; i++)
    {
        cin >> distance[i];
    }
    for (long long i = 0; i < N; i++)
    {
        cin >> oil[i];
    }
    long long smallest_oil_price = oil[0];
    long long city = 0;
    long long sum = 0;
    while (city < N - 1)
    {
        //cout << smallest_oil_price << ", " << distance[city] << "\n";
        smallest_oil_price = min(smallest_oil_price, oil[city]);
        sum += smallest_oil_price * distance[city];
        city += 1;
    }

    cout << sum;
}
