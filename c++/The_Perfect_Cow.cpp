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
    int N, half;
    cin >> N;
    half = (N - 1) / 2;
    vector<int> cows(N, 0);
    vector<int> average(N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> cows[j];
        }
        sort(cows.begin(), cows.end());
        average[i] = cows[half];
    }
    sort(average.begin(), average.end());
    
    cout << average[half];
}
