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
vector<int> vec(pow(101, 3) + 1, 0);
int get_w(int a, int b, int c)
{
    return vec[101 * 101 * (a + 50) + 101 * (b + 50) + c + 50];
}
void set_w(int a, int b, int c, int d)
{
    vec[101 * 101 * (a + 50) + 101 * (b + 50) + c + 50] = d;
}
int w(int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0)
    {
        set_w(a, b, c, 1);
    }

    if (a > 20 || b > 20 || c > 20)
    {
        if (!get_w(a, b, c))
            set_w(a, b, c, w(20, 20, 20));
    }

    if (a < b && b < c)
    {
        if (!get_w(a, b, c))
            set_w(a, b, c, w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c));
    }

    else
    {
        if (!get_w(a, b, c))
            set_w(a, b, c, w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1));
    }
    //cout << a << ", " << b << ", " << c << ", " << get_w(a, b, c) << "\n";
    return get_w(a, b, c);
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    while (true)
    {
        int a, b, c;
        
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1) break;
        //cout << "cout" << a << ", " << b << ", " << c << "\n";

        printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
        //break;
    }
}
