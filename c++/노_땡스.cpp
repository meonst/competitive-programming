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
    vector<int> cards(N);
    for (int i = 0; i < N; i++)
    {
        cin >> cards[i];
    }

    int score = cards[0];

    for (int i = 1; i < N; i++)
    {
        if (cards[i] != cards[i - 1] + 1) score += cards[i];
    }
    
    cout << score;
}
