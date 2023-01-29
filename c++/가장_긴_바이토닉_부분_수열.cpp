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

vector<long> input(1000);
vector<long> max_containing(1000, -1);
vector<long> reverse_max_containing(1000, -1);
long get_max_containing(int here)
{
    if (max_containing[here] == -1)
    {
        long longest = 1;
        for (int i = 0; i < here; i++)
        {
            if (input[i] < input[here])
                longest = max(longest, get_max_containing(i) + 1);
        }
        max_containing[here] = longest;
    }
    return max_containing[here];
}

long get_reverse_max_containing(int here, int last)
{
    if (reverse_max_containing[here] == -1)
    {
        long longest = 1;
        for (int i = last; i > here; i--)
        {
            if (input[i] < input[here])
                longest = max(longest, get_reverse_max_containing(i, last) + 1);
        }
        reverse_max_containing[here] = longest;
    }
    return reverse_max_containing[here];
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    long longest = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
        get_max_containing(i);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        get_reverse_max_containing(i, n - 1);
    }

    for (int i = 0; i < n; i++)
    {
        //cout << i << " : " << get_max_containing(i) << ", " << get_reverse_max_containing(i, n - 1) << "\n";
        longest = max(get_max_containing(i) + get_reverse_max_containing(i, n - 1) - 1, longest);
    }
    cout << longest;
}
