#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<bool> mobis(5, false);
    
    string stickers;
    cin >> stickers;
    int count = 0;
    for (int i = 0; i < stickers.size(); i++)
    {
        if (stickers[i] == 'M' && !mobis[0])
        {
            mobis[0] = true;
            count += 1;
        }
        if (stickers[i] == 'O' && !mobis[1])
        {
            mobis[1] = true;
            count += 1;
        }
        if (stickers[i] == 'B' && !mobis[2])
        {
            mobis[2] = true;
            count += 1;
        }
        if (stickers[i] == 'I' && !mobis[3])
        {
            mobis[3] = true;
            count += 1;
        }
        if (stickers[i] == 'S' && !mobis[4])
        {
            mobis[4] = true;
            count += 1;
        }
    }

    cout << (count == 5 ? "YES" : "NO");

}
