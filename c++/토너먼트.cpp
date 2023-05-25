#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, A, B;
    int count = 0;
    cin >> N >> A >> B;
    A -= 1;
    B -= 1;
    while (A != B)
    {
        count += 1;
        A /= 2;
        B /= 2;
    }
    cout << count;
}
