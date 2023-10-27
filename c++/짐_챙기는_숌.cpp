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
    int count = 0;
    int weight = M + 1;
    for (int i = 0; i < N; i++)
    {
        int item;
        cin >> item;

        if (weight + item > M) 
        {
            count += 1;
            weight = item;
        }
        else
        {
            weight += item;
        }

    }
    cout << count;
}
