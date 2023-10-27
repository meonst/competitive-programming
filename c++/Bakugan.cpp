#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while (true)
    {
        int n;
        cin >> n;
        if (n == 0) break;
        bool consecutive_bonus = false;
        bool consecutive_bonus_mark = false;
        bool consecutive_bonus_leti = false;

        int consecutive_count_mark = 0;
        int consecutive_count_leti = 0;

        int score_mark = 0;
        int score_leti = 0;

        vector<int> mark(n);
        vector<int> leti(n);
        
        for (int i = 0; i < n; i++)
        {
            cin >> mark[i];
            score_mark += mark[i];
        }

        for (int i = 0; i < n; i++)
        {
            cin >> leti[i];
            score_leti += leti[i];
        }
        
        for (int i = 2; i < n; i++)
        {
            if (consecutive_bonus) break;

            if (mark[i] == mark[i - 1] && mark[i] == mark[i - 2])
            {
                score_mark += 30;
                consecutive_bonus = true;
            }

            if (leti[i] == leti[i - 1] && leti[i] == leti[i - 2])
            {
                score_leti += 30;
                consecutive_bonus = true;
            }
        }

        if (score_mark > score_leti) cout << "M\n";
        if (score_mark == score_leti) cout << "T\n";
        if (score_mark < score_leti) cout << "L\n";
    }
}
