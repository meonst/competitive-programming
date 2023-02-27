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

class absol
{
    public:
    bool operator() (ll a, ll b)
    {
        ll absol_a = a < 0 ? (-1 * a) : a;
        ll absol_b = b < 0 ? (-1 * b) : b;
        if (absol_a == absol_b) return a > b;
        else return absol_a > absol_b;
    }
};
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    priority_queue<ll, vector<ll>, absol> numbers;
    int N;
    ll x = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> x;
        if (x == 0)
        {
            if (numbers.size() == 0) cout << "0\n";
            else
            {
                cout << numbers.top() << "\n";
                numbers.pop();
            }
        }
        else
        {
            numbers.push(x);
        }
    }
}
