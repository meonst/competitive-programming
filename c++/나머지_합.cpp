
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

long N, M, a;
long summer = 0;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    vector<long> sum(N + 1, 0);
    unordered_map<long, long> count;
    
    cin >> a;
    sum[1] = a % M;
    count[sum[1]] = 1;
    for (int i = 2; i < N + 1; i++)
    {
        cin >> a;
        sum[i] = (sum[i - 1] + a) % M;
        if (count.find(sum[i]) == count.end())
        {
            count[sum[i]] = 1;
        }
        else
        {
            count[sum[i]] += 1;
        }
    }

    if (count.find(0) != count.end())
    {
        summer = count[0];
    }

    for (auto i : count)
    {
        summer += i.second * (i.second - 1) / 2;
        //cout << i.first << ", " << i.second << "\n";
    }
    cout << summer;
}
