#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    string last;
    string word;
    bool finished = false;
    cin >> n;
    unordered_map<string, bool> words;

    cin >> last;
    words[last] = true;

    for (int i = 1; i < n; i++)
    {
        cin >> word;
        if (last[last.size() - 1] != word[0])
        {
            finished = true;
            cout << "Player " << (i % 2 == 0 ? "1" : "2") << " lost";
            break;
        }
        else
        {
            if (words.find(word) == words.end())
            {
                words[word] = true;
            }
            else
            {
                finished = true;
                cout << "Player " << (i % 2 == 0 ? "1" : "2") << " lost";
                break;
            }
        }
        last = word;
    }

    if (!finished)
    {
        cout << "Fair Game";
    }
}
