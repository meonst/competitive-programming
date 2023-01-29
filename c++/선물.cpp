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
    long long N, L, W, H;
    cin >> N >> L >> W >> H;
    double max_a = min(min(L, W), H);
    double min_a = 0;
    double half;
    long long l, w, h;
    
    for (int i = 0; i < 1000; i++)
    {
        
        half = (min_a + max_a) / 2;
        l = L / half;
        w = W / half;
        h = H / half;
        
        if (l * w * h < N)
        {
            max_a = half;
        }
        else
        {
            min_a = half;
        }
    }
    cout << std::setprecision(30) << half;
}
