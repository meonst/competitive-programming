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
    int N;
    cin >> N;
    vector<int> max_profit(N + 1, 0);
    vector<int> counseling_time(N);
    vector<int> counseling_fee(N);
    for (int i = 0; i < N; i++)
    {
        int time, fee;

        cin >> time >> fee;
        if (i + time > N) fee = 0;
        counseling_time[i] = time;
        counseling_fee[i] = fee;
    }
    int j;
    for (int i = 0; i < N; i++)
    {
        if (i > 0) max_profit[i] = max(max_profit[i], max_profit[i - 1]);
        int target = i + counseling_time[i];    
        if (target > N) continue;
        max_profit[target] = max(max_profit[target], max_profit[i] + counseling_fee[i]);
        //cout << "1: " << i << ", " << max_profit[i] << "\n";
    }
    cout << max(max_profit[N], max_profit[N - 1]);
}
