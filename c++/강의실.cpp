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

int classroom = 0;
int classes, class_number;
vector<int> classroom_available_from;
bool class_fits;

bool compare_first_element(const vector<int> &a, const vector<int> &b)
{
    return a[0] < b[0];
}
// bool is_classroom_available(const vector<int> &a)
// {
//     if (classroom_available_from <= a[0])
//     {
//         classroom_available_from = a[1];
//         return true;
//     }
//     return false;
// }
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> classes;
    vector<vector<int>> c(classes, vector<int>(2));

    for (int i = 0; i < classes; i++)
    {
        // ignore class_number here!
        cin >> class_number >> c[i][0] >> c[i][1];
    }

    sort(c.begin(), c.end(), compare_first_element);

    for (int i = 0; i < classes; i++)
    {
        class_fits = false;
        class_number = classroom_available_from.size();

        for (int j = 0; j < class_number; j++)
        {
            if (classroom_available_from[j] <= c[i][0])
            {
                classroom_available_from[j] = c[i][1];
                class_fits = true;
                break;
            }
        }
        if (!class_fits)
        {
            classroom_available_from.insert(classroom_available_from.end(), c[i][1]);
        }
    }


    cout << classroom_available_from.size();
}
