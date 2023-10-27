#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> parent;

bool bigger(vector<double> &a, vector<double> &b)
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
    int N;
    double sum = 0;
    cin >> N;
    parent.resize(N + 1);
    for (int i = 1; i <= N; i++)
    {
        parent[i] = i;
    }

    vector<vector<double>> edges;
    vector<pair<double, double>> freckles;
    freckles.push_back({0, 0});
    for (double i = 1; i <= N; i+=1)
    {
        double x, y;
        cin >> x >> y;
        freckles.push_back({x, y});
        // cout << "freckles: " << i << ", " << x << ", " << y << "\n";
        if (i == 1) continue;
        for (double j = 1; j < i; j+=1)
        {
            double distance = sqrt(pow(freckles[i].first - freckles[j].first, 2) + pow(freckles[i].second - freckles[j].second, 2));
            edges.push_back({i, j, distance});
        }
        
    }
    sort(edges.begin(), edges.end(), bigger);
    

    for (int i = 0; i < edges.size(); i++)
    {
        int node1 = edges[i][0];
        int node2 = edges[i][1];
    
        // cout << i << ": " << edges[i][0] << ", " << edges[i][1] << ", " << edges[i][2] << "\n";
        if (getParent(node1) == getParent(node2)) continue;
        sum += edges[i][2];
        merge(node1, node2);
    }

    cout << fixed << setprecision(2) << sum;

}
