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
    for (int i = 0; i < n; i++)
    {
        int match, max_match, min_match;
        cin >> match;
        max_match = match;
        min_match = match;

        string max = "";
        string min = "";

        if (max_match % 2 == 1)
        {
            max_match -= 3;
            max.append("7");
        }
        while (max_match > 0)
        {
            max.append("1");
            max_match -= 2;
        }
        

        cout << min << " " << max << "\n";;
        

    }
}


/*
1 -> 2
7 -> 3
4 -> 4
2 -> 5
6 -> 6
0 -> 6
8 -> 7
*/