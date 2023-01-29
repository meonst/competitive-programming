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
    int width, height, count, direction, position;
    vector<int> horizontal, vertical;
    cin >> width >> height >> count;
    horizontal.push_back(0);
    vertical.push_back(0);
    horizontal.push_back(width);
    vertical.push_back(height);
    for (int i = 0; i < count; i++)
    {
        cin >> direction >> position;
        if (direction == 0) vertical.push_back(position);
        else horizontal.push_back(position);
    }
    sort(horizontal.begin(), horizontal.end());
    sort(vertical.begin(), vertical.end());
    int max_horizontal = 0;
    int max_vertical = 0;
    for (int i = 0; i < vertical.size() - 1; i++)
    {
        max_vertical = max(max_vertical, vertical[i + 1] - vertical[i]);
    }
    for (int i = 0; i < horizontal.size() - 1; i++)
    {
        max_horizontal = max(max_horizontal, horizontal[i + 1] - horizontal[i]);
    }
    cout << max_horizontal * max_vertical;
}
