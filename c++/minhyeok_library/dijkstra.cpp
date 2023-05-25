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
int V, E, K;

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