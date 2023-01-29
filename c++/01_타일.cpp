
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

vector<int> end0(1000001, 0);
vector<int> end1(1000001, 0);


int get(int n, int last)
{
    if (last == 0)
    {
        if (n == 0) return 0;
        if (n == 1) return 0;
        if (n == 2) return 1;
        if (!end0[n]) end0[n] = (get(n - 2, 0) + get(n - 2, 1)) % 15746;
        return end0[n];
    }
    else
    {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 1;
        if (!end1[n]) end1[n] = (get(n - 1, 0) + get(n - 1, 1)) % 15746;
        return end1[n];
    }
}



int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;

    cin >> N;
    //printf("%d %d", get(4, 0), get(4, 1));
    printf("%d", get(N + 1, 1));

    

    
}
