#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string A, B;
    char op;
    cin >> A >> op >> B;
    if (op == '*')
    {
        int length = A.length() + B.length();
        cout << "1";
        for (int i = 2; i < length; i++)
        {
            cout << "0";
        }
    }
    else
    {
        vector<int> answer(300, 0);
        bool print = false;
        
        answer[300 - A.length()] += 1;
        answer[300 - B.length()] += 1;
        
        for (int i = 0; i < 300; i++)
        {
            if (!print && answer[i] != 0) print = true;

            if (print) cout << answer[i];
        }
    }

}
