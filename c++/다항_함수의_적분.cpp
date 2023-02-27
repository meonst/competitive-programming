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

int get_value(string a)
{
    return int(a[0]);
}

bool is_number(string a)
{
    int value = get_value(a);
    return (48 <= value && value <= 57);
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string formula;
    cin >> formula;
    string string1 = "";
    string string2 = "";
    for (int i = 1; i < formula.size(); i++)
    {
        if (formula[i] == '+' || formula[i] == '-')
        {
            string1 = formula.substr(0, i - 1);
            string2 = formula.substr(i, formula.size() - i);
        }
    }
    if (string1 == "" && string2 == "")
    {
        if (formula[formula.size() - 1] == 'x')
        {
            string1 = formula.substr(0, formula.size() - 1);
        }
        else
        {
            string2 = formula;
        }
    }
    //cout << "1: " << string1 << ", " << string2 << "\n";
    if (string1 != "")
    {
        if (string1 == "2")
        {
            cout << "xx";
        }
        else if (string1 == "-2")
        {
            cout << "-xx";
        }
        else 
        {
            cout << stoi(string1) / 2 << "xx";
        }
    }

    if (string2 != "")
    {
        if (string2 == "+1") cout << "+x";
        else if (string2 == "-1") cout << "-x";
        else if (string2 == "1") cout << "x";
        else if (string2 != "0" && string2 != "+0" && string2 != "-0") cout << string2 << "x";
        
    }
    if (string2 == "0") cout << "W";
    else cout << "+W";
}
