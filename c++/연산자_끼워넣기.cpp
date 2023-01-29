
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

vector<int> numbers(11, 0);
int n;
void backtrack(int last)
{
    c.push_back(last);
    if (checq()) 
    {   
        c.pop_back();
        return;
    }
    if (c.size() == n)
    {
        cases += 1;

        // for (int j = 0; j < c.size(); j++)
        // {
        //     cout << c[j] << " ";
        // }
        // cout << " is not checq\n";

        c.pop_back();
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            backtrack(i);
        }
        c.pop_back();
    }
}


int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        backtrack(i);
    }
    cout << cases;
}
