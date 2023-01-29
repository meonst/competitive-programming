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
    int N;
    int count2 = 0;
    int count5 = 0;
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        int A = i;
        int B = i;

        while (true)
        {
            if (A % 2 == 0)
            {
                count2 += 1;
                A /= 2;
            }
            else break;
        }
        while (true)
        {
            if (B % 5 == 0)
            {
                count5 += 1;
                B /= 5;
            }
            else break;
        }
    }

    cout << min(count2, count5);
}
