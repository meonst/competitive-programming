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
    int N, x;
    cin >> N;
    vector<int> numbers(N);
    for (int i = 0; i < N; i++)
    {
        cin >> numbers[i];
    }
    cin >> x;
    sort(numbers.begin(), numbers.end());
    int i = 0;
    int j = N - 1;
    
    int count = 0;
    while (i != j)
    {
        int sum = numbers[i] + numbers[j];
        if (sum == x)
        {
            count += 1;
            j -= 1;
        }
        else if (sum > x)
        {
            j -= 1;
        }
        else if (sum < x)
        {
            i += 1;
        }
    }
    cout << count;
    

}
