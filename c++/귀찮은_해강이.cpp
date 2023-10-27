#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


vector<int> parent;

int get_parent(int a)
{
    if (parent[a] == a) return a;
    return get_parent(parent[a]);
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    parent.resize(N + 1);
    for (int i = 1; i <= N; i++)
    {
        parent[i] = i;
    }

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        parent[a] = get_parent(a);
        parent[b] = get_parent(b);
        if (parent[a] > parent[b])
        {
            parent[parent[a]] = parent[b];
        }
        else
        {
            parent[parent[b]] = parent[a];
        }
        
    }

    int before;
    cin >> before;
    int count = 0;
    int now;
    for (int i = 1; i < N; i++)
    {
        cin >> now;
        if (get_parent(before) != get_parent(now))
        {
            count += 1;
        }
        before = now;
    }
    cout << count;
}