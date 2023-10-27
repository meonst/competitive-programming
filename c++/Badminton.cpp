#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string a;
    cin >> a;
    int match_score_a = 0;
    int match_score_b = 0;
    int game_score_a = 0;
    int game_score_b = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == 'A')
        {
            game_score_a += 1;
        }
        else
        {
            game_score_b += 1;
        }

        if (game_score_a == 21)
        {
            cout << game_score_a << "-" << game_score_b << "\n";
            game_score_a = 0;
            game_score_b = 0;

            match_score_a += 1;
        }
        else if (game_score_b == 21)
        {
            cout << game_score_a << "-" << game_score_b << "\n";
            game_score_a = 0;
            game_score_b = 0;

            match_score_b += 1;
        }
    }    
    cout << (match_score_a == 2 ? "A" : "B");
}
