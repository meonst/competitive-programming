#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int case_number = 1;
    while (true)
    {
        string a, b;
        bool same = false;
        cin >> a >> b;
        if (a == "END" && b == "END") break;
        
        if (a.size() == b.size())
        {
            vector<int> a_count(26, 0);
            vector<int> b_count(26, 0);

            for (int i = 0; i < a.size(); i++)
            {
                a_count[a[i] - 97] += 1;
                b_count[b[i] - 97] += 1;
            }
            int same_count = 0;
            for (int i = 0; i < 26; i++)
            {
                if (a_count[i] == b_count[i]) same_count++;
            }
            if (same_count == 26) same = true;
        }

        cout << "Case " << case_number++ << ": " << (same ? "same" : "different") << "\n";
    }
}
