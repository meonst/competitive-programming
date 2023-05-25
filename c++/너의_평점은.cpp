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
#include <regex>
#include <stdio.h>
#include <stdlib.h>
#include <cassert>
#include <queue>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    double sum = 0;
    double count = 0;
    for (int i = 0; i < 20; i++)
    {
        string a;
        double b;
        string c;
        double score;
        cin >> a >> b >> c;

        if (c != "P")
        {
            if (c == "A+") score = 4.5;
            if (c == "A0") score = 4.0;
            if (c == "B+") score = 3.5;
            if (c == "B0") score = 3.0;
            if (c == "C+") score = 2.5;
            if (c == "C0") score = 2.0;
            if (c == "D+") score = 1.5;
            if (c == "D0") score = 1.0;
            if (c == "F") score = 0;
            sum += score * b;
            count += b;
        }
        
    }
    cout << sum / count;
}
