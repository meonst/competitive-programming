#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int A, B, C;
    cin >> A >> B >> C;
    int sum = A + B + C - min(min(A, B), C);
    cout << sum;
}
