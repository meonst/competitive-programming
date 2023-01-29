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
    int cases, n;
    cin >> cases;
    string item, category;
    unordered_map<string, int> equipments;
    for (int i = 0; i < cases; i++)
    {
        int count = 1;
        equipments.clear();
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            cin >> item >> category;
            if (equipments[category]) equipments[category] += 1;
            else equipments[category] = 1;
        }
        for (auto a : equipments) 
        {
            //cout << a.first << " : " << a.second << "\n";
            count *= (a.second + 1);
        }
        cout << count - 1 << "\n";
    }
}
