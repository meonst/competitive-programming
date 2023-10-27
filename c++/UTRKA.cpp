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
    vector<string> contestants(n);
    vector<string> finished(n);
    finished[0] = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
    for (int i = 0; i < n; i++)
    {
        cin >> contestants[i];
    }
    for (int i = 1; i < n; i++)
    {
        cin >> finished[i];
    }

    sort(contestants.begin(), contestants.end()); 
    sort(finished.begin(), finished.end());

    for (int i = 0; i < n; i++)
    {
        if (contestants[i] != finished[i])
        {
            cout << contestants[i];
            break;
        }
        //cout << contestants[i] << ", " << finished[i] << "\n";
    }
}
