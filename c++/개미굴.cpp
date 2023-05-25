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


typedef vector<string> ant_basement;
typedef map<string, ant_basement> ant_floor;
typedef vector<ant_floor> ant_nest;


ant_nest nest;

void print_minus(int depth)
{
    for (int i = 0; i < depth; i++)
        cout << "--";
}

void print_nest(int depth, string key)
{
    print_minus(depth);
    int last = key.find_last_of('*');
    if (last == string::npos)
    {
        cout << key << "\n";
    }
    else
    {
        cout << key.substr(last + 1, key.size() - 1 - last) << "\n";
    }

    
    sort(nest[depth][key].begin(), nest[depth][key].end());
    for (int i = 0; i < nest[depth][key].size(); i++)
    {
        print_nest(depth + 1, nest[depth][key][i]);
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int k;
        cin >> k;
        while (nest.size() < k)
        {
            ant_floor floor;
            nest.push_back(floor);
        }
        string ceiling;
        cin >> ceiling;
        if (nest[0].find(ceiling) == nest[0].end())
        {
            ant_basement basement;
            nest[0][ceiling] = basement;
        }
        for (int j = 1; j < k; j++)
        {
            string food;
            cin >> food;
            string a = ceiling;
            food = a.append("*").append(food);
            if (find(nest[j - 1][ceiling].begin(), nest[j - 1][ceiling].end(), food) == nest[j - 1][ceiling].end())
                nest[j - 1][ceiling].push_back(food);

            if (nest[j].find(food) == nest[j].end())
            {
                ant_basement basement;
                nest[j][food] = basement;
            }
            ceiling = food;
        }
    }
    //cout << nest[0]["APPLE-BANANA"][0];
    int depth = 0;

    
    for (const auto [key, value]: nest[0])
    {
        //cout << key << ", ";
        print_nest(depth, key);
    }
    
}
