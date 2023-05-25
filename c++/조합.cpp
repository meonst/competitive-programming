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



vector<ll> smooth(vector<ll> a)
{
    for (int i = a.size() - 1; i >= 0; i--)
    {
        if (a[i] > 10)
        {
            ll b = a[i] / 10;
            a[i] = a[i] % 10;
            a[i - 1] += b;
        }
    }
    return a;
}
vector<ll> multiply(vector<ll> a, ll b)
{
    vector<ll> answer(300, 0);
    for (int i = a.size() - 1; i >= 0; i--)
    {
        ll aa = a[i] * b;
        ll count = 0;
        while (aa > 0)
        {
            answer[i - count] += aa % 10;
            count += 1;
            aa /= 10;
        }
    }
    return smooth(answer);
}

vector<ll> divide(vector<ll> a, ll b)
{
    vector<ll> answer(300, 0);
    for (int i = 0; i < a.size(); i++)
    {
        ll aa = a[i] / b;
        ll aaa = a[i] % b;

        answer[i] = aa;
        if (i + 1 != a.size())
            a[i + 1] += aaa * 10;
    }
    return smooth(answer);
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<ll> a(300, 0);
    a[299] = 1;

    ll n, m;
    cin >> n >> m;
    for (ll i = 1; i <= m; i++)
    {
        a = multiply(a, n - i + 1); 
        a = divide(a, i); 
    }

    bool print = false;
    for (int i = 0; i < a.size(); i++)
    {
        if (!print && a[i] != 0)
            print = true;
            
        if (print)
            cout << a[i];
    }

}
