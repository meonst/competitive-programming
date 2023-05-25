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
#include <stdio.h>
#include <stdlib.h>
#include <cassert>
#include <queue>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll A, B;
    cin >> A >> B;
    vector<int> list(10000, 0);

    int ind = 1;
    for (int i = 1; i < 80; i++)
    {
        for (int j = 0; j < i; j++)
        {
            list[ind] = i;
            ind += 1;
        }
    }

    ll sum = 0;
    for (int i = A; i <= B; i++)
    {
        sum += list[i];
    }
    cout << sum;
}
