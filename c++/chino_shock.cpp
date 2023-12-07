#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string emoji;
    cin >> emoji;
    int score = emoji.size() + 2;
    for (int i = 0; i < emoji.size(); i++)
        if (emoji[i] == '_') score += 5;
    cout << score;
}
