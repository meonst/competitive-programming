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

int N, M;
vector<int> list;
void dive(vector<int> now, int depth)
{
    if (depth == M) 
    {
        for (int i = 0; i < now.size(); i++)
        {
            cout << now[i] << " ";
        }
        cout << "\n";
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            if (find(now.begin(), now.end(), list[i]) == now.end())
            {
                now.push_back(list[i]);
                dive(now, depth + 1);
                now.pop_back();
            }
        }
    }
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        list.push_back(a);
    }
    sort(list.begin(), list.end());
    vector<int> now;
    dive(now, 0);
}
