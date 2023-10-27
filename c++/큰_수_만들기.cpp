#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// true when a going front is less
bool less_string(string a, string b)
{
    string ab = a + b;
    string ba = b + a;
    for (int i = 0; i < ab.size(); i++)
    {
        if (ab[i] < ba[i]) return true;
        if (ab[i] > ba[i]) return false;
    }
    return a < b;
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    vector<string> numbers(N);
    for (int i = 0; i < N; i++) cin >> numbers[i];

    sort(numbers.begin(), numbers.end(), less_string);
    string answer = "";
    bool print = false;
    for (int i = N - 1; i >= 0; i--)
    {
        for (int j = 0; j < numbers[i].size(); j++)
        {
            if (!print)
            {
                if (numbers[i][j] == '0') continue;
                else
                {
                    print = true;
                    cout << numbers[i][j];
                }
            }
            else
            {
                cout << numbers[i][j];
            }
        }
    }
    if (!print) cout << "0";
}
