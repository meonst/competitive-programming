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
    int N, in, in2;
    cin >> N;
    priority_queue<int, vector<int>, less<int>> smaller_than_half;
    priority_queue<int, vector<int>, greater<int>> bigger_than_half;
    cin >> in;
    cout << in << "\n";
    smaller_than_half.push(in);

    for (int i = 1; i < N; i++)
    {
        cin >> in;

        if (smaller_than_half.size() == bigger_than_half.size())
        {
            bigger_than_half.push(in);
            smaller_than_half.push(bigger_than_half.top());
            bigger_than_half.pop();
        }
        else
        {
            smaller_than_half.push(in);
            bigger_than_half.push(smaller_than_half.top());
            smaller_than_half.pop();
        }


        cout << smaller_than_half.top() << "\n";
    }
}
