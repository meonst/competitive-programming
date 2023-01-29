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
    bool cannot = true;
    cin >> N;
    vector<long long> straws(N);
    for (int i = 0; i < N; i++)
    {
        cin >> straws[i];
    }
    sort(straws.begin(), straws.end());
    for (int i = 1; i < N - 1; i++)
    {
        if (straws[N - i] < straws[N - i - 1] + straws[N - i - 2])
        {
            cout << straws[N - i] + straws[N - i - 1] + straws[N - i - 2];
            cannot = false;
            break;
        }
    }
    if (cannot) cout << -1;
}
