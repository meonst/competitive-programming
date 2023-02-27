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
    int N, x, y;
    int a = (-3) / 2;
    cout << a;
    ll sum_x = 0;
    ll sum_y = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> x >> y;
        if (i == 0) cout << y << " " << x << "\n";
        else if (i == 0) cout << (sum_y < y ? sum_y : y) << " " << sum_x
    }

}
