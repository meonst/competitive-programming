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
    int score = 1;
    int score_sum = 0;

    for (int i = 0; i < N; i++)
    {
        int answer;
        cin >> answer;
        if (answer == 1)
        {
            score_sum += score;
            score += 1;
        }
        else
        {
            score = 1;
        }
    }
    cout << score_sum;
}
