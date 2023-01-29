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


vector<int> pole(501, 0);
vector<int> pole_ordered(501, 0);
vector<int> max_containing(501, 0);
int get_max_containing(int here)
{

    if (max_containing[here] == 0)
    {
        int longest = 1;
        for (int i = 0; i < here; i++)
        {
            if (pole_ordered[i] < pole_ordered[here])
                longest = max(longest, get_max_containing(i) + 1);
        }
        max_containing[here] = longest;
    }
    return max_containing[here];
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;   
    for (int i = 0; i < n; i++)
    {
        int out, in;
        cin >> out >> in;
        pole[out] = in;
    }
    int count = 0;
    for (int i = 0; i < 501; i++)
    {
        if (pole[i])
        {
            pole_ordered[count] = pole[i];
            count += 1;
        }
    }
    int longest = -1;
    for (int i = 0; i < 501; i++)
    {
        if (pole_ordered[i] != 0)
        {
            longest = max(get_max_containing(i), longest);
        }
        else break;
    }
    // for (int i = 0; i < 501; i++)
    // {
    //     if (pole_ordered[i] != 0)
    //     {
    //         cout << i << " : " << get_max_containing(i) << "\n";
    //     }
    //     else break;
    // }
    //cout << longest << "\n";
    cout << n - longest;
}
