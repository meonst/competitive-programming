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
int sum_of_numbers(int n)
{
    int sum = 0;

    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T, N, NN, j, last_ten, last_sum;
    bool exists;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> N;
        last_ten = N / 10 % 10 - 1;
        NN = 0;
        exists = false;
        for (j = N; j < N + 83; j++)
        {
            if (last_ten == j / 10 % 10)
            {
                last_sum += 1;
            }
            else
            {
                last_sum = sum_of_numbers(j);
                last_ten = j / 10 % 10;
            }

            if (last_sum == NN) 
            {
                exists = true;
                break;
            }
            NN++;
        }
        cout << (exists ? j : -1) << " ";
    }
}
