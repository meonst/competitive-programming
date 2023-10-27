#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> parent;

bool bigger(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}

int getParent(int &node)
{
    return (parent[node] == node ? node : getParent(parent[node]));
}

void merge(int node1, int node2)
{
	node1 = getParent(node1);
	node2 = getParent(node2);

	if (node1 < node2) 
        parent[node2] = node1;
	else 
        parent[node1] = node2;
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int V, E;
    cin >> V >> E;
    parent.resize(V + 1);
    for (int i = 1; i <= V; i++)
    {
        parent[i] = i;
    }

    ll sum = 0;
    ll total_cost = 0;

    vector<vector<int>> edges;
    

    for (int i = 0; i < E; i++)
    {
        int node1, node2, weight;
        cin >> node1 >> node2 >> weight;
        total_cost += weight;
        vector<int> edge = vector<int> {node1, node2, weight};

        edges.push_back(edge);
    }
    sort(edges.begin(), edges.end(), bigger);
    int number_of_edges = 0;
    for (int i = 0; i < E; i++)
    {
        if (getParent(edges[i][0]) == getParent(edges[i][1])) continue;

        number_of_edges += 1;
        sum += edges[i][2];
        merge(edges[i][0], edges[i][1]);
    }


    if (number_of_edges < V - 1) cout << -1;
    else cout << total_cost - sum;

}
