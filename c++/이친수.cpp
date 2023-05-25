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

vector<ll> ends_with_nil(91, 0);
vector<ll> ends_with_one(91, 0);
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    ends_with_nil[1] = 0; ends_with_one[1] = 1;
    
    for (int i = 2; i < 91; i++)
    {
        ends_with_nil[i] = ends_with_nil[i - 1] + ends_with_one[i - 1];
        ends_with_one[i] = ends_with_nil[i - 1];
    }
    cout << ends_with_nil[N] + ends_with_one[N];
    
    
}
