#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<char> key_product(vector<char> key1, vector<char> key2)
{
    vector<char> new_key(100);

    for (int i = 65; i < 91; i++)
    {
        new_key[i] = key2[key1[i]];
    }
    new_key[95] = key2[key1[95]];

    return new_key;
}

vector<char> key_power(vector<char> key, int n)
{
    if (n == 1)
    {
        return key;
    }
    else if (n == 2)
    {
        return key_product(key, key);
    }
    else if (n % 2 == 0)
    {
        vector<char> new_key = key_power(key, n / 2);
        return key_product(new_key, new_key);
    }
    else
    {
        vector<char> new_key = key_power(key, n / 2);
        return key_product(key_product(new_key, new_key), key);
    }
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<char> key(100);
    for (int i = 65; i < 91; i++)
    {
        cin >> key[i];
    }
    cin >> key[95];

    int n;
    cin >> n;

    string t;
    cin >> t;
    int length = t.size();
    vector<char> T(length);
    for (int i = 0; i < length; i++)
    {
        T[i] = t[i];
    }

    key = key_power(key, n);

    // for (int i = 65; i < 91; i++)
    // {
    //     cout << key[i] << " ";
    // }
    // cout << key[95] << "\n";

    for (int i = 0; i < length; i++)
    {

        cout << key[T[i]];
    }
}
