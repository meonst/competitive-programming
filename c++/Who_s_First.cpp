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
        int N;
        cin >> N;
        if (N == 0) break;
        map<string, string> words;
        for (int i = 0; i < N; i++)
        {
            string original;
            cin >> original;
            string lower = original;
            for (int j = 0; j < lower.size(); j++)
            {
                if (lower[j] <= 90) lower[j] += 32;
            }
            words[lower] = original;
        }
        cout << words.begin() -> second << "\n";
    }
}
