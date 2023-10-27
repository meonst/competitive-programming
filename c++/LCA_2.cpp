#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<pair<int, list<int>>> nodes;

int lca = -1;
bool lca_found = false;
int first_descendant, second_descendant;

void find_parent(int node)
{
    for (auto i = nodes[node].second.begin(); i != nodes[node].second.end();)
    {
        if (*i == nodes[node].first)
        {
            nodes[node].second.erase(i++);
        }
        else
        {
            nodes[*i].first = node;
            find_parent(*i);
            i++;
        }
    }
}

pair<bool, bool> find_ancestor(int node)
{
    if (lca_found) return {true, true};
    pair<bool, bool> ans = {false, false};

    for (auto i = nodes[node].second.begin(); i != nodes[node].second.end(); i++)
    {

        pair<bool, bool> child_ans = find_ancestor(*i);

        if (lca_found) return {true, true};
        if (child_ans.first) ans.first = true;
        if (child_ans.second) ans.second = true;
    }

    if (node == first_descendant) ans.first = true;
    if (node == second_descendant) ans.second = true;

    if (ans.first && ans.second)
    {
        lca = node;
        lca_found = true;
    }
    return ans;
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M, a, b;
    cin >> N;

    nodes = vector<pair<int, list<int>>>(N + 1, {-1, list<int>{}});


    for (int i = 0; i < N - 1; i++)
    {
        cin >> a >> b;
        nodes[a].second.push_back(b);
        nodes[b].second.push_back(a);
    }

    find_parent(1);
    
    cin >> M;
    for (int i = 0; i < M; i++)
    {

        cin >> first_descendant >> second_descendant;

        lca_found = false;

        find_ancestor(1);
        cout << lca << "\n";
    }
}

