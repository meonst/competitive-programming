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
    int N, x;
    cin >> N;
    vector<int> stack;
    for (int i = 0; i < N; i++)
    {
        cin >> x;
        if (x)
        {
            stack.push_back(x);
        }
        else
        {
            stack.pop_back();
        }
    }
    int sum = 0;
    for (int i = 0; i < stack.size(); i++)
    {
        sum += stack[i];
    }
    cout << sum;

}
