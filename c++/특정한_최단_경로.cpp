#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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

vector<vector<pair<int, int>>> routes;
int V, E;

vector<ll> dijkstra(int start)
{
    vector<ll> distance = vector<ll>(V, numeric_limits<ll>::max());
    priority_queue<pair<int, int>, vector<pair<int, int>>, less<>> q;
    distance[start] = 0;
    q.push(pair<int, int> {0, start});
    while (!q.empty())
    {
        int current_position = q.top().second;
        int current_distance = -q.top().first;
        q.pop();

        if (distance[current_position] < current_distance)
            continue;

        for (int i = 0; i < routes[current_position].size(); i++)
        {
            int dist = routes[current_position][i].second + current_distance;
            if (dist < distance[routes[current_position][i].first])
            {
                distance[routes[current_position][i].first] = dist;
                q.push(pair<int, int> {-dist, routes[current_position][i].first});
            }
        }
    }
    return distance;
}


int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> V >> E;
    routes.resize(V);
    for (int i = 0; i < E; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        routes[a - 1].push_back({b - 1, c});
        routes[b - 1].push_back({a - 1, c});
    }
    int detour1, detour2;
    cin >> detour1 >> detour2;
    detour1 -= 1;
    detour2 -= 1;

    vector<ll> d_start = dijkstra(0);
    vector<ll> d_1 = dijkstra(detour1);
    vector<ll> d_2 = dijkstra(detour2);

    int r_1 = -1;
    int r_2 = -1;

    if (d_start[detour1] != numeric_limits<ll>::max() &&
        d_1[detour2] != numeric_limits<ll>::max() &&
        d_2[V - 1] != numeric_limits<ll>::max())
    {
        r_1 = d_start[detour1] + d_1[detour2] + d_2[V - 1];
    }

    if (d_start[detour2] != numeric_limits<ll>::max() &&
        d_2[detour1] != numeric_limits<ll>::max() &&
        d_1[V - 1] != numeric_limits<ll>::max())
    {
        r_2 = d_start[detour2] + d_2[detour1] + d_1[V - 1];
    }

    if (r_1 == -1 && r_2 == -1)
    {
        cout << - 1;
    }
    else
    {
        if (r_1 == -1)
        {
            cout << r_2;
        }
        else if (r_2 == -1)
        {
            cout << r_1;
        }
        else
        {
            cout << min(r_1, r_2);
        }
    }

}
