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
    vector<int> num(N);
    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
    }
    int a = 0;
    int b = 0;
    int sum = num[0];
    int count = 0;
    while (a < N)
    {
        if (sum < M)
        {
            if (b == N - 1)
            {
                break;
            }
            b += 1;
            sum += num[b];
        }
        else if (sum == M)
        {
            count += 1;
            //cout << "1: " << a << ", " << b << "\n";
            sum -= num[a];
            a += 1;
        }
        else if (sum > M)
        {
            sum -= num[a];
            a += 1;
        }
    }
    cout << count;
}
