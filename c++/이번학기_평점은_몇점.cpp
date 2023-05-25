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
    int point_sum = 0;
    double score_sum = 0;
    for (int i = 0; i < N; i++)
    {
        string a, score;
        int points;
        cin >> a >> points >> score;
        point_sum += points;

        if (score == "A+") score_sum += 4.3 * points;
        if (score == "A0") score_sum += 4.0 * points;;
        if (score == "A-") score_sum += 3.7 * points;;

        if (score == "B+") score_sum += 3.3 * points;;
        if (score == "B0") score_sum += 3.0 * points;;
        if (score == "B-") score_sum += 2.7 * points;;

        if (score == "C+") score_sum += 2.3 * points;;
        if (score == "C0") score_sum += 2.0 * points;;
        if (score == "C-") score_sum += 1.7 * points;;

        if (score == "D+") score_sum += 1.3 * points;;
        if (score == "D0") score_sum += 1.0 * points;;
        if (score == "D-") score_sum += 0.7 * points;;

        if (score == "F") score_sum += 0;
    }
    double score_final = round((score_sum / point_sum) * 100) / 100;
    printf("%.2lf", score_final);

}
