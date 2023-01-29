
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

vector<string> padovan(101, "not calculated");

string stringAdd(string a, string b)
{
    int addTen= 0;
    string result = "";
    while ((a.length() > 0) || (b.length() > 0)) 
    {
        int aBack = 0;
        int bBack = 0;

        if (a.length() > 0) 
        {
            aBack = a.back() - '0';
            a.pop_back();
        }
        if (b.length() > 0) 
        {
            bBack = b.back() - '0';
            b.pop_back();
        }

        int sum = aBack + bBack + addTen;
        addTen = (sum >= 10) ? 1 : 0;
        
        result.insert(0, to_string(sum % 10));
    }
    if (addTen == 1) result.insert(0, "1");
    return result;
}

string get(int n)
{
    if (n == 1) return "1";
    if (n == 2) return "1";
    if (n == 3) return "1";
    if (n == 4) return "2";
    if (n == 5) return "2";
    if (n == 6) return "3";
    if (n == 7) return "4";
    if (n == 8) return "5";
    if (n == 9) return "7";
    if (n == 10) return "9";
    
    if (padovan[n] == "not calculated") padovan[n] = stringAdd(get(n - 1), get(n - 5));
    return padovan[n];

}



int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;

    int N;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> N;
        cout << get(N) << "\n";
    }
}
