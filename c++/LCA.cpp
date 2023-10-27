#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<list<int>> children_nodes;
vector<vector<int>> nodes;

void find_parent(int node)
{
    nodes[node][2] = node;
    for (auto i = children_nodes[node].begin(); i != children_nodes[node].end();)
    {
        if (*i != nodes[node][0])
        {
            nodes[*i][0] = node;
            nodes[*i][1] = nodes[node][1] + 1;
            find_parent(*i);
        }
        i++;
    }
}

int find_ancestor(int node1, int node2)
{
    if (nodes[node1][1] <= nodes[node2][1])
    {
        int temp = node2;
        node2 = node1;
        node1 = temp;
    }
    while (nodes[node1][1] > nodes[node2][1])
    {
        node1 = nodes[node1][0];
    }
    
    while (nodes[node1][2] != nodes[node2][2])
    {
        node1 = nodes[node1][0];
        node2 = nodes[node2][0];
    }
    return nodes[node1][2];
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M, a, b;
    cin >> N;
    children_nodes.resize(N + 1);

    // parent, depth, self
    nodes = vector<vector<int>>(N + 1, {0, 0, 0});
    

    for (int i = 0; i < N - 1; i++)
    {
        cin >> a >> b;
        children_nodes[a].push_back(b);
        children_nodes[b].push_back(a);
    }

    find_parent(1);
    
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int first, second;
        cin >> first >> second;
        cout << find_ancestor(first, second) << "\n";;
    }
}

