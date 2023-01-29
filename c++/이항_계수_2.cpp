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
    long long N, M;
    cin >> N >> M;
    long long remainder1 = 1;
    long long remainder2 = 1;
    for (long long i = 1; i <= M; i++)
    {
        remainder1 = (remainder1 * i) % 10007;
        remainder2 = (remainder2 * (i + N - M)) % 10007;
    }
    //cout << remainder1 << ", " << remainder2 << "\n";
    for (long long j = 1; j <= 10007; j++)
    {
        if (!((remainder1 * j - remainder2) % 10007))
        {
            cout << j;
            break;
        }
    }
}

//10007 i + a = (10007 j + b)(10007 k + c) = 10007 * 100007 * j + b + 10007 * (bk + jc) + bc
