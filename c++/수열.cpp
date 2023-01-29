
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
    int N, M;
    cin >> N >> M;
    int sum = 0;
    int number;
    vector<int> summer(N, 0);
    for (int i = 0; i < N; i++)
    {

        cin >> number;
        sum += number;
        summer[i] = sum;
    }
    int maxi = summer[M - 1];
    for (int i = M; i < N; i++)
    {
        maxi = max(maxi, summer[i] - summer[i - M]);
    }
    cout << maxi;
}
