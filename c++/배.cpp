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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int crane_count, box_count, box_weight, j;
    cin >> crane_count;
    vector<int> crane_capacity(crane_count);
    vector<int> boxes_liftable(crane_count, 0);
    for (int i = 0; i < crane_count; i++)
    {
        cin >> crane_capacity[i];
    }
    cin >> box_count;

    bool able = true;
    
    sort(crane_capacity.begin(), crane_capacity.end());

    // sort crane by power

    for (int i = 0; i < box_count; i++)
    {
        cin >> box_weight;

        if (box_weight > crane_capacity[crane_count - 1])
        {
            able = false;
            break;
        }
        for (j = 0; j < crane_count; j++)
        {
            if (crane_capacity[j] >= box_weight) break;
        }
        // get which is the weakest crane able to lift this box
        boxes_liftable[j] += 1;
    }

    if (able)
    {
        for (j = 0; j < crane_count; j++)
        {
            if (crane_capacity[j] > 0) break;
        }
        // get where to start
        // cout << start << "\n";
        
        int count = 0;
        int sum = 0;
        for (int i = crane_count - 1; i >= j; i--)
        {
            sum += boxes_liftable[i];
            int compare = sum / (crane_count - i) + (sum % (crane_count - i) == 0 ? 0 : 1);
            count = max(compare, count);
        }
        cout << count;
    }
    else
    {
        cout << -1;
    }
}
