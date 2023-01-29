
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


int a;
int b;
vector<int> c;
//unordered_map<vector<int>, bool> done;

void backtrack(int last)
{
    //cout << "last : " << last << "\n";
    // if (find(c.begin(), c.end(), last) == c.end())
    // {
        c.push_back(last);

        if (c.size() == b)
        {
            for (int i = 0; i < b; i++)
            {
                cout << c[i] << " ";
            }
            cout << "\n";
            // done[c] = true;
            c.pop_back();
        }
        else
        {
            for (int i = c.back(); i <= a; i++)
            {
                backtrack(i);
            }
            c.pop_back();
        }
    // }
}


int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> a >> b;
    for (int i = 1; i <= a; i++)
    {
        backtrack(i);
    }
}
