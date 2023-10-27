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
    for (int i = 0; i < N; i++)
    {
        int pos;
        string word;
        cin >> pos >> word;
        for (int j = 1; j <= word.size(); j++)
        {
            if (pos == j) continue;
            cout << word[j - 1];
        }
        cout << "\n";
    }
}
