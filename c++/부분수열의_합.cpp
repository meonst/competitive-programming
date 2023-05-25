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

int N, S, x;
int a = 0;
vector<int> first_sums;
vector<int> second_sums;
vector<int> first_half;
vector<int> second_half;
bool bigger(int a, int b)
{
    return a > b;
}
void dfs(int index, int sum)
{
    if (index >= first_half.size())
    {
        if (S == sum)
        {
            a += 1;
        }
        return;
    }
    dfs(index + 1, sum + first_half[index]);
    dfs(index + 1, sum);
}


int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> S;
    for (int i = 0; i < N; i++)
    {
        cin >> x;
        first_half.push_back(x);
    }
    dfs(0, 0);
    if (S == 0) a -= 1;
    cout << a;

}
