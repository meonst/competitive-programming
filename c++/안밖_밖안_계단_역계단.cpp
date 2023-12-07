#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string a;
    cin >> a;
    if (a == "fdsajkl;" || a == "jkl;fdsa")
    {
        cout << "in-out";
    }
    else if (a == "asdf;lkj" || a == ";lkjasdf")
    {
        cout << "out-in";
    }
    else if (a == "asdfjkl;")
    {
        cout << "stairs";
    }
    else if (a == ";lkjfdsa")
    {
        cout << "reverse";
    }
    else 
    {
        cout << "molu";
    }
}
