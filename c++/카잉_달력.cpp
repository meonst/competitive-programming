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
    int T, M, N, x, y;
    int a, b, m;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> M >> N >> x >> y;
        int years = x;
        while (years <= lcm(M, N))
        {
            //cout << "1: " << years << ", " << years % N << ", " << y << "\n";
            int remainder = years % N;
            if (remainder == 0) remainder = N;
            if (remainder == y)
            {
                break;
            }
            years += M;
        }
        cout << (years > lcm(M, N) ? -1 : years) << "\n";
    }
    

}