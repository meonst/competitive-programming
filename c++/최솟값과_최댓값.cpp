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

struct segment_tree_minimum
{
    ll default_value = 1000000001;
    ll size;
    vector<ll> tree;
    vector<ll> leaves;
    ll merge(ll left_value, ll right_value)
    {
        return min(left_value, right_value);
    }

    void grow(const vector<ll> leaf)
    {   
        leaves = leaf;
        size = leaves.size();
        tree.resize(size * 4);

        recursive_grow(1, 0, size - 1);
    }
    
    ll recursive_grow(int node, int start, int end) // initialize the value from 'start' to 'end' in leaves for node
    {
        if (start == end)
            return tree[node] = leaves[start];

        ll half = start + (end - start) / 2;
        ll left_value = recursive_grow(node * 2, start, half);
        ll right_value = recursive_grow(node * 2 + 1, half + 1, end);
        return tree[node] = merge(left_value, right_value);
    }

    ll get(ll start, ll end)
    {
        return recursive_get(start, end, 1, 0, size - 1);
    }

    ll recursive_get(ll start, ll end, ll node, ll node_start, ll node_end)
    {
        if (end < node_start || node_end < start)
            return default_value;
        
        if (start <= node_start && node_end <= end)
            return tree[node];

        ll node_half = node_start + (node_end - node_start) / 2;
        return merge(
            recursive_get(start, end, node * 2, node_start, node_half),
            recursive_get(start, end, node * 2 + 1, node_half + 1, node_end)
        );
    }
    ll recursive_update(ll index, ll new_value, ll node, ll node_start, ll node_end)
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

    void update(ll index, ll new_value)
    {
        recursive_update(index, new_value, 1, 0, size - 1);
    }
};

struct segment_tree_maximum
{
    ll default_value = 0;
    ll size;
    vector<ll> tree;
    vector<ll> leaves;
    ll merge(ll left_value, ll right_value)
    {
        return max(left_value, right_value);
    }

    void grow(const vector<ll> leaf)
    {   
        leaves = leaf;
        size = leaves.size();
        tree.resize(size * 4);

        recursive_grow(1, 0, size - 1);
    }
    
    ll recursive_grow(int node, int start, int end) // initialize the value from 'start' to 'end' in leaves for node
    {
        if (start == end)
            return tree[node] = leaves[start];

        ll half = start + (end - start) / 2;
        ll left_value = recursive_grow(node * 2, start, half);
        ll right_value = recursive_grow(node * 2 + 1, half + 1, end);
        return tree[node] = merge(left_value, right_value);
    }

    ll get(ll start, ll end)
    {
        return recursive_get(start, end, 1, 0, size - 1);
    }

    ll recursive_get(ll start, ll end, ll node, ll node_start, ll node_end)
    {
        if (end < node_start || node_end < start)
            return default_value;
        
        if (start <= node_start && node_end <= end)
            return tree[node];

        ll node_half = node_start + (node_end - node_start) / 2;
        return merge(
            recursive_get(start, end, node * 2, node_start, node_half),
            recursive_get(start, end, node * 2 + 1, node_half + 1, node_end)
        );
    }
    ll recursive_update(ll index, ll new_value, ll node, ll node_start, ll node_end)
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

    void update(ll index, ll new_value)
    {
        recursive_update(index, new_value, 1, 0, size - 1);
    }
};

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll N, M;
    cin >> N >> M;
    vector<ll> numbers(N);
    for (int i = 0; i < N; i++)
    {
        cin >> numbers[i];
    }
    segment_tree_maximum max_tree;
    segment_tree_minimum min_tree;
    max_tree.grow(numbers);
    min_tree.grow(numbers);
    ll a, b;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        a--;
        b--;
        cout << min_tree.get(a, b) << " " << max_tree.get(a, b) << "\n";
    }
}
