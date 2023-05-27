#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (int i = 0; i < 3; i++)
    {
        int sh, sm, ss, eh, em, es;
        cin >> sh >> sm >> ss >> eh >> em >> es;
        int start = sh * 3600 + sm * 60 + ss;
        int end = eh * 3600 + em * 60 + es;
        int time = end - start;
        int hours = time / 3600;
        time %= 3600;
        int minutes = time / 60;
        time %= 60;
        int seconds = time;
        cout << hours << " " << minutes << " " << seconds << "\n";

    }
}
