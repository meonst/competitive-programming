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
    int E, S, M;
    cin >> E >> S >> M;
    int i = 1;
    for (i; i < 7981; i++)
    {
        if (i % 15 == E % 15 && i % 28 == S % 28 && i % 19 == M % 19) break;   
    }
    cout << i;
}
