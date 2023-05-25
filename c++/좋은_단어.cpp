#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int count = 0;
    int N;

    cin >> N;
    for (int words = 0; words < N; words++)
    {
        string word;
        cin >> word;
        stack<char> chars;
        for  (int i = 0; i < word.size(); i++)
        {
            if (chars.empty() || chars.top() != word[i]) 
            {
                chars.push(word[i]);
            }
            else
            {
                chars.pop();
            }
            
        }
        if (chars.empty()) count += 1;
    }
    cout << count;
}
