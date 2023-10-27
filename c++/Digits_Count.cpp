#include <bits/stdc++.h>
using namespace std;
typedef long long ll;




vector<ll> get_count(int N)
{
    vector<ll> count(10, 0);

    

}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while (true)
    {
        int A, B;
        cin >> A >> B;
        if (A == 0 && B == 0) break;

        vector<ll> A_count = get_count(A);
        vector<ll> B_count = get_count(B);

        for (int i = 0; i < 10; i++)
        {
            cout << B_count[i] - A_count[i] << " ";
        }
        cout << "\n";

    }
}
