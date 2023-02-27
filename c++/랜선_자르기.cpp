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
vector<int> bits;
int K, N;
bool enough(int half)
{
    int count = 0;
    for (int i = 0; i < K; i++)
    {
        count += bits[i] / half;
    }
    return count >= N;
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> K >> N;
    
    long long min = 0;
    long long max = 2147483647;
    long long half = (min + max) / 2;
    for (int i = 0; i < K; i++)
    {
        int length;
        cin >> length;
        bits.push_back(length);
    }

    for (int i = 0; i < 100; i++)
    {
        half = (min + max) / 2;
        if (enough(half))
        {
            min = half;
        }
        else
        {
            max = half;
        }
    }
    if (enough(half + 1)) cout << half + 1;
    else cout << half;
}
