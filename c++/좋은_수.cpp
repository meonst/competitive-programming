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
vector<int> S;
class better 
{
    public:
    bool operator() (int a, int b)
    {
        if (a > S.back() && b > S.back())
        {
            return a < b;
        }
        else if (b > S.back())
        {
            return true;
        }
        else if (a > S.back())
        {
            return false;
        }
        else
        {

        }
    }
};

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    priority_queue<int, vector<int>, better> numbers;
    int L, n;
    cin >> L;
    for (int i = 0; i < L; i++)
    {
        cin >> n;
        S.push_back(n);
    }
    sort(S.begin(), S.end());
    cin >> n;

}
