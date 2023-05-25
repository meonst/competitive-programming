#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    vector<vector<pair<int, int>>> bus_routes(N + 1);
    for (int i = 0; i < M; i++)
    {
        int start, end, time;
        cin >> start >> end >> time;
        bus_routes[start].push_back(pair<int, int> {end, time});
    }
    int starting_city, ending_city;
    cin >> starting_city >> ending_city;
    vector<ll> shortest_time(N + 1, 10000000009);
    shortest_time[starting_city] = 0;
    
    priority_queue<pair<ll, int>> q;
    q.push(pair<ll, int> {0, starting_city});
    
    while (!q.empty())
    {
        ll current_time = -q.top().first;
        int current_position = q.top().second;
        q.pop();
        if (current_time > shortest_time[current_position]) continue;

        for (int i = 0; i < bus_routes[current_position].size(); i++)
        {
            ll time_spent = bus_routes[current_position][i].second + current_time;
            int destination = bus_routes[current_position][i].first;
            if (time_spent < shortest_time[destination])
            {
                shortest_time[destination] = time_spent;
                q.push(pair<int, int> {-time_spent, destination});
            }
        }
    }
    // for (int i = 1; i <= N; i++)
    // {
    //     cout << shortest_time[i] << " ";
    // }
    cout << shortest_time[ending_city];

}
