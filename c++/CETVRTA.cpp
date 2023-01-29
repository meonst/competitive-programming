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
using namespace std;

int main()
{
    int x1, x2, x3, x4, y1, y2, y3, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    if (x1 == x2) x4 = x3;
    else if (x2 == x3) x4 = x1;
    else if (x3 == x1) x4 = x2;

    if (y1 == y2) y4 = y3;
    else if (y2 == y3) y4 = y1;
    else if (y3 == y1) y4 = y2;
    printf("%d %d", x4, y4);
}
