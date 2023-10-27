#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int chat_count;
    string winner;
    cin >> chat_count >> winner;
    vector<pair<string, string>> chat_log(chat_count);


    string answer;
    for (int i = 0; i < chat_count; i++)
    {
        cin >> chat_log[i].first >> chat_log[i].second;
        if (chat_log[i].first == winner) answer = chat_log[i].second;
    }

    
    
    int count = 0;
    for (int i = 0; i < chat_count; i++)
    {
        if (chat_log[i].first == winner) break;
        if (chat_log[i].second == answer) count += 1;
    }
    cout << count;

}
