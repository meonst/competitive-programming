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

long long how_many(long long start, long long end, long long what)
{
    long long power = what;
    long long count = 0;
    long long start_quotient;
    long long end_quotient;
    while (power <= end)
    {
        if (!(start % power)) count += 1;
        start_quotient = start / power;
        end_quotient = end / power;
        count += (end_quotient - start_quotient);
        power *= what;
    }
    return count;
}


int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long N, M;
    long long count2;
    long long count5;
    cin >> N >> M;
    count2 = how_many(N - M + 1, N, 2) - how_many(1, M, 2);
    count5 = how_many(N - M + 1, N, 5) - how_many(1, M, 5);
    //cout << how_many(N - M + 1, N, 2) << ", " << how_many(1, M, 2) << ", " << how_many(N - M + 1, N, 5)  << ", " << how_many(1, M, 5) << "\n";
    cout << min(count2, count5);
}
