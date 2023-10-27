#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    vector<int> score(N);
    for (int i = 0; i < N; i++)
    {
        cin >> score[i];
    }
    int sum = 0;
    for (int i = N - 2; i >= 0; i--)
    {
        if (score[i] >= score[i + 1])
        {
            sum += score[i] - score[i + 1] + 1;;
            score[i] -= score[i] - score[i + 1] + 1;
        }
    }
    cout << sum;
}
