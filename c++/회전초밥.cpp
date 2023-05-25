#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class bigger
{
    public:
    bool operator() (ll a, ll b)
    {
        return a > b;
    }
};

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    vector<priority_queue<int, vector<int>, bigger>> queue(200001);
    vector<int> C(N, 0);
    for (int i = 0; i < N; i++)
    {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            int A;
            cin >> A;
            queue[A].push(i);
        }
    }
    for (int i = 0; i < M; i++)
    {
        int B;
        cin >> B;
        if (queue[B].empty()) continue;
        
        int who_ate_this = queue[B].top();
        queue[B].pop();
        C[who_ate_this] += 1;
    }
    for (int i = 0; i < N; i++)
    {
        cout << C[i] << " ";
    }
}
