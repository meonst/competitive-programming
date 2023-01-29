
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

vector<long> input(100000);
vector<long> max_containing(100000, -1001);
long get_max_containing(int here)
{
    if (here == 0) max_containing[here] = input[here];
    if (max_containing[here] == -1001)
    {
        max_containing[here] = max(get_max_containing(here - 1) + input[here], input[here]);
    }
    return max_containing[here];
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    long biggest = -1001;
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
        //cout << i << ", " << get_max_containing(i) << "\n";
        biggest = max(get_max_containing(i), biggest);
    }
    cout << biggest;

    
}
