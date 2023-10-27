#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


bool is_prime(int a)
{
    bool is_prime = true;
    for (int i = 2; i < a; i++)
    {
        if (a % i == 0)
        {
            is_prime = false;
            break;
        }
    }
    return is_prime;
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string word;
    cin >> word;
    int sum = 0;
    for (int i = 0; i < word.size(); i++)
    {
        if (65 <= word[i] && word[i] <= 90)
        {
            sum += word[i] - 38;
        }
        else if (97 <= word[i] && word[i] <= 122)
        {
            sum += word[i] - 96;
        }
    }
    if (is_prime(sum))
    {
        cout << "It is a prime word.";
    }
    else
    {
        cout << "It is not a prime word.";
    }
}
