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
    for (int i =  0; i < T; i++)
    {
        cin >> M >> N >> x >> y;
        m = M / gcd(M, N);
        n = N / gcd(M, N);
        for (a = 0; a < M; a++)
        {
            if (a * n % M == x) break;
        }
        for (b = 0; b < N; b++)
        {
            if (b * m % N == y) break;
        }
        int LCM = lcm(M, N);
        cout << a << ", " << b << "\n";
        int sum = (a * n + b * m) % LCM;
        if (sum % M == x && sum % N == y)
            cout << sum << "\n";
        else
            cout << -1 << "\n";
    }
    

}