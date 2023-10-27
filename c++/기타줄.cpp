#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    int half_a_dozen = 1001;
    int single = 1001;
    for (int i = 0; i < M; i++)
    {
        int six, one;
        cin >> six >> one;
        half_a_dozen = min(half_a_dozen, six);
        single = min(single, one);
    }
    int sixs = N / 6;
    int ones = N % 6;
    
    if (half_a_dozen >= 6 * single)
    {
        cout << (single * N);
    }
    else
    {
        if (sixs * half_a_dozen + ones * single > (sixs + 1) * half_a_dozen)
        {
            cout << ((sixs + 1) * half_a_dozen);
        }
        else
        {
            cout << (sixs * half_a_dozen + ones * single);
        }
        
    }
}
