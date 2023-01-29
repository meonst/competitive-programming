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
    string board;
    string covered = "";
    cin >> board;
    int count = 0;
    for (int i = 0; i < board.length(); i++)
    {
        if (board.at(i) == 'X')
        {
            count += 1;
            if (count == 4)
            {
                covered.append("AAAA");
                count = 0;
            }
        }
        else if (board.at(i) == '.')
        {
            if (count % 2 == 1)
            {
                covered = "-1";
                break;
            }
            else if (count == 2)
            {
                covered.append("BB");
                count = 0;
            }
            else if (count == 4)
            {
                covered.append("AAAA");
                count = 0;
            }
            covered.append(".");
        }
    }
    if (count % 2 == 1)
    {
        covered = "-1";
    }
    else if (count == 2)
    {
        covered.append("BB");
        count = 0;
    }
    else if (count == 4)
    {
        covered.append("AAAA");
        count = 0;
    }
    cout << covered;
}
