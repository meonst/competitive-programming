#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class bigger
{
    public:
    bool operator() (pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
};

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, d;
    cin >> N;
    priority_queue<pair<int, int>, vector<pair<int, int>>, bigger> pq;
    vector<pair<int, int>> location(N);
    
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        location[i].first = min(a, b);
        location[i].second = max(a, b);
    }

    cin >> d;
    int maxi = 0;

    sort(location.begin(), location.end());
    int start = location[0].first;
    
    for (int i = 0; i < N; i++)
    {
        if (start + d >= location[i].second)
        {
            pq.push(location[i]);
        }
        else
        {
            int pq_size = pq.size();
            // cout << i << ", " << pq_size << "\n";
            maxi = max(maxi, pq_size);

            while (!pq.empty() && pq.top().first + d < location[i].second)
            {
                pq.pop();
            }
            if (location[i].first + d >= location[i].second)
            {
                pq.push(location[i]);
                start = pq.top().first;
            }
            else if (i != N - 1)
            {
                start = location[i + 1].first;
            }
        }
    }
    cout << maxi << "\n";
    // for (int i = 0; i < N; i++)
    // {
    //     cout << location[i].first << ", " << location[i].second << "\n";
    //     pq.push(location[i]);
    // }
    // cout << "asd: " << pq.top().first << ", " << pq.top().second;
}
