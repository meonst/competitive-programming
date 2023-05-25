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


int cut;
int N;
vector<vector<int>> tree;

int get_leaves(int node)
{
    if (node == cut) return 0;
    int children_count = 0;
    for (int i = 0; i < tree[node].size(); i++)
    {
        if (tree[node][i] == cut) 
        {
            continue;
        }
        children_count += get_leaves(tree[node][i]);
    }
    if (children_count == 0) children_count += 1;
    // cout << "node: " << node << ", " << "count: " << children_count << "\n";
    return children_count;
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    int begin;
    for (int i = 0; i < N; i++)
    {
        tree.push_back(vector<int> {});
    }
    for (int i = 0; i < N; i++)
    {
        int parent;
        cin >> parent;
        if (parent != -1)
        {
            tree[parent].push_back(i);
        }
        else 
        {
            begin = i;
        }
    }
    cin >> cut;

    // for (int i = 0; i < N; i++)
    // {
    //     cout << i << ": ";
    //     for (int j = 0; j < tree[i].size(); j++)
    //     {
    //         cout << tree[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    int leaves = get_leaves(begin);
    cout << leaves;

    
}
