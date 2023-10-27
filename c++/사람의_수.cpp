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
    vector<double> average(N);
    for (int i = 0; i < N; i++)
    {
        cin >> average[i];
    }
    int count = 1;
    while (true)
    {   
        bool possible = true;
        for (int i = 0; i < N; i++)
        {
            int a = average[i] * count;
            int b = a - 1;
            int c = a + 1;

            double aa = a / count

            if (a == b) continue;
            possible = false;
            break;
        }
        if (possible) break;
        count++;
    }
    cout << count;
}
