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



typedef long long ll;

struct segment_tree
{
    ll size;
    vector<vector<ll>> tree;
    vector<vector<ll>> leaves;


    vector<ll> identity = vector<ll> {1000000001, 1000000001};
    vector<ll> merge(vector<ll> left_value, vector<ll> right_value)
    {
        if (left_value[1] <= right_value[1])
        {
            return left_value;
        }
        else
        {
            return right_value;
        }
    }


    void grow(const vector<vector<ll>> leaf)
    {   
        leaves = leaf;
        size = leaves.size();
        tree.resize(size * 4);

        recursive_grow(1, 0, size - 1);
    }
    
    vector<ll> recursive_grow(int node, int start, int end) // initialize the value from 'start' to 'end' in leaves for node
    {
        if (start == end)
            return tree[node] = leaves[start];

        ll half = start + (end - start) / 2;
        vector<ll> left_value = recursive_grow(node * 2, start, half);
        vector<ll> right_value = recursive_grow(node * 2 + 1, half + 1, end);
        return tree[node] = merge(left_value, right_value);
    }

    vector<ll> get(ll start, ll end)
    {
        return recursive_get(start, end, 1, 0, size - 1);
    }

    vector<ll> recursive_get(ll start, ll end, ll node, ll node_start, ll node_end)
    {
        if (end < node_start || node_end < start)
            return identity;
        
        if (start <= node_start && node_end <= end)
            return tree[node];

        ll node_half = node_start + (node_end - node_start) / 2;
        return merge(
            recursive_get(start, end, node * 2, node_start, node_half),
            recursive_get(start, end, node * 2 + 1, node_half + 1, node_end)
        );
    }
    vector<ll> recursive_update(ll index, vector<ll> new_value, ll node, ll node_start, ll node_end)
    {
        if (index < node_start || node_end < index)
            return tree[node];

        if (node_start == node_end)
            return tree[node] = new_value;

        ll node_half = node_start + (node_end - node_start) / 2;

        return tree[node] = merge(
            recursive_update(index, new_value, node * 2, node_start, node_half),
            recursive_update(index, new_value, node * 2 + 1, node_half + 1, node_end)
        );
    }

    void update(ll index, vector<ll> new_value)
    {
        recursive_update(index, new_value, 1, 0, size - 1);
    }
};

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    vector<vector<ll>> numbers(N, vector<ll>(2));
    for (int i = 0; i < N; i++)
    {
        numbers[i][0] = i;
        cin >> numbers[i][1];
    }
    segment_tree tree;
    tree.grow(numbers);
    int M;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
        {
            b -= 1;
            tree.update(b, vector<ll> {b, c});
        }
        else
        {
            b -= 1;
            c -= 1;
            cout << tree.get(b, c)[1] << "\n";
        }
    }
}

