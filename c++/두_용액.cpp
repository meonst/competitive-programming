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


    int N;
    cin >> N;

    vector<int> solution(N);
    for (int i = 0; i < N; i++)
    {
        cin >> solution[i];
    }
    sort(solution.begin(), solution.end());

    int i = 0;
    int j = N - 1;
    
    int count = 0;
    int minimum = 2000000009;
    int first, second;
    while (i != j)
    {
        int sum = solution[i] + solution[j];
        if (abs(sum) < minimum)
        {
            minimum = abs(sum);
            first = solution[i];
            second = solution[j];
        }
        if (sum < 0)
        {
            i += 1;
        }
        else if (sum > 0)
        {
            j -= 1;
        }
        else
        {
            break;
        }

    }
    cout << first << " " << second;
}
