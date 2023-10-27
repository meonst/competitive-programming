#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, m, M, T, R;
    cin >> N >> m >> M >> T >> R;

    int exercise_time = 0;
    int elapsed_time = 0;
    int current_pulse_rate = m;
    while (true)
    {
        if (exercise_time == N) break;

        if (current_pulse_rate == m && current_pulse_rate + T > M)
        {
            elapsed_time = -1;
            break;
        }
        else if (current_pulse_rate + T <= M)
        {
            exercise_time += 1;
            elapsed_time += 1;

            current_pulse_rate += T;
        }
        else
        {
            elapsed_time += 1;
            current_pulse_rate = max(m, current_pulse_rate - R);
        }
    }
    cout << elapsed_time;
}
