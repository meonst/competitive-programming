#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


vector<int> parent;
int get_parent(int a)
{
    if (parent[a] == a) return a;
    parent[a] = get_parent(parent[a]);
    return parent[a];
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;

    parent.resize(N + 1);
    for (int i = 1; i <= N; i++)
    {
        parent[i] = i;
    }
        
    for (int i = 0; i < N - 2; i++)
    {
        int a, b;
        cin >> a >> b;
        get_parent(a);
        get_parent(b);
        if (parent[a] > parent[b])
        {
            parent[parent[a]] = parent[b];
        }
        else
        {
            parent[parent[b]] = parent[a];
        }
    }

    for (int i = 1; i <= N; i++)
    {
        if (get_parent(1) != get_parent(i))
        {
            cout << 1 << " " << i;
            break;
        }
    }
}   
