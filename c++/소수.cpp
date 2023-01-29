
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
    int A, B, N;
    cin >> A >> B >> N;

    while (N >= 0)
    {
        N -= 1;
        A = (A % B) * 10;
        if (N == 0)
        {
            cout << (A / B);
        }
    }
}
