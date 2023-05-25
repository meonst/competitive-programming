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
vector<vector<int>> constraints_1;
vector<vector<int>> constraints_2;
ll c = 0;
int T, N;

bool impossible(vector<int> toppings, vector<int> constraint_2)
{
    int count = 0;
    for (int i = 0; i < constraint_2.size(); i++)
    {
        if (toppings[constraint_2[i]] == 1)
        {
            count += 1;
        }
    }
    if (count == constraint_2.size())
        return true;
    else
        return false;

}


void DFS(int topping, int max, vector<int> toppings)
{
    if (topping == max)
    {
        c += 1;
        // for (int i = 0; i < T; i++)
        // {
        //     cout << toppings[i] << " ";
        // }
        // cout << "\n";
        return;
    }
    DFS(topping + 1, max, toppings);


    bool possible = true;

    toppings[topping] = 1;
    for (int i = 0; i < N; i++)
    {
        if (constraints_1[i][topping] != 1) continue;
        if (impossible(toppings, constraints_2[i])) 
        {
            possible = false;
            break;
        }
    }
    if (possible)
        DFS(topping + 1, max, toppings);
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T >> N;
    
    for (int i = 0; i < N; i++)
    {
        int a;
        int b;
        cin >> a;
        vector<int> constraint_1(T, 0);
        vector<int> constraint_2(a);
        for (int j = 0; j < a; j++)
        {
            cin >> b;
            constraint_1[b - 1] = 1;
            constraint_2[j] = b - 1;
        }
        constraints_1.push_back(constraint_1);
        constraints_2.push_back(constraint_2);
    }
    // cout << "constraint 1\n";
    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < T; j++)
    //     {
    //         cout << constraints_1[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "constraint 2\n";
    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < constraints_2[i].size(); j++)
    //     {
    //         cout << constraints_2[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    vector<int> toppings(T, 0);
    DFS(0, T, toppings);
    cout << c;
}
