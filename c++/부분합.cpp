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
    int N, S;
    cin >> N >> S;
    vector<int> numbers(N + 1);
    numbers[0] = 0;
    cin >> numbers[1];
    for (int i = 2; i <= N; i++) 
    {
        int number;
        cin >> number;
        numbers[i] = number + numbers[i - 1];
    }
    int i = 1;
    int j = 1;
    int minimum = 100001;
    while (j <= N)
    {
        int sum = numbers[j] - numbers[i - 1];
        int length = j - i + 1;
        if (sum >= S && length < minimum) minimum = length;
        if (sum < S) j += 1;
        else if (sum >= S) i += 1;
    }
    if (minimum == 100001) cout << 0;
    else cout << minimum;   
}
