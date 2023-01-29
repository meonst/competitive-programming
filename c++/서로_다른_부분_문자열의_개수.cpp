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
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string S;
    cin >> S;
    unordered_map<string, int> distinct;
    int count = 0;
    for (int i = 1; i <= S.length(); i++)
    {
        for (int j = 0; j <= S.length() - i; j++)
        {
            if (distinct[S.substr(j, i)] != 1)
            {
                count += 1;
                distinct[S.substr(j, i)] = 1;
            }
        }
    }
    cout << count;
}
