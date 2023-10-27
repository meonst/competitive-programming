#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string word;
        cin >> word;
        char last = 'a';
        for (int j = 0; j < word.size(); j++)
        {
            if (last == word[j]) continue;
            
            last = word[j];
            cout << word[j];
        }
        cout << "\n";
    }
}
