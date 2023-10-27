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
    vector<int> conversion(100, 0);
    conversion['A'] = 2;
    conversion['B'] = 2;
    conversion['C'] = 2;
    conversion['D'] = 3;
    conversion['E'] = 3;
    conversion['F'] = 3;
    conversion['G'] = 4;
    conversion['H'] = 4;
    conversion['I'] = 4;
    conversion['J'] = 5;
    conversion['K'] = 5;
    conversion['L'] = 5;
    conversion['M'] = 6;
    conversion['N'] = 6;
    conversion['O'] = 6;
    conversion['P'] = 7;
    conversion['Q'] = 7;
    conversion['R'] = 7;
    conversion['S'] = 7;
    conversion['T'] = 8;
    conversion['U'] = 8;
    conversion['V'] = 8;
    conversion['W'] = 9;
    conversion['X'] = 9;
    conversion['Y'] = 9;
    conversion['Z'] = 9;

    for (int i = 0; i < n; i++)
    {
        string number;
        cin >> number;
        int digit = 0;
        for (int j = 0; j < number.size(); j++)
        {
            if (number[j] == '-') continue;
            if (digit > 9) break;
            if (48 <= number[j] && number[j] <= 57)
            {
                cout << number[j];
                digit += 1;
            }
            else
            {
                cout << conversion[number[j]];
                digit += 1;
            }
            if (digit == 3 || digit == 6) cout << "-";
        }

        cout << "\n";
    }
}
