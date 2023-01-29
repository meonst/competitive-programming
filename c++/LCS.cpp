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

string first;
string second;
vector<vector<int>> max(1000, vector<int>(1000, -1));
// max[i][j] denotes 
// max[i][j] is the length of the subsequence ending with first[i] and second[j]
// by definition first[i] == second[j]

int longest = 0;

int get_max(int i, int j)
{
    if (max[i][j] == -1)
    {
        if (i == 0 || j == 0)
        {
            if (first[i] == second[j])
            {
                max[i][j] = 1;
            }
            else 
            {
                max[i][j] = 0;
            }
        }
        else
        {
            
        }
    }
    else
    {
        return max[i][j];
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> first, second;


    for (int i = 0; i < first.length(); i++)
    {
        for (int j = 0; j < second.length(); j++)
        {
            longest = max(longest, get_max(i, j));
        }
    }

    //cout << longest;
}
