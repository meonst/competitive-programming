#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M, J;
    cin >> N >> M >> J;
    int start = 1;
    int end = M;
    int distance = 0;
    
    for (int i = 0; i < J; i++)
    {
        int apple;
        cin >> apple;
        if (start <= apple && apple <= end) continue;
        
        if (start > apple)
        {
            int diff = start - apple;
            start -= diff;
            end -= diff;
            distance += diff;
        }
        else if (end < apple)
        {
            int diff = apple - end;
            start += diff;
            end += diff;
            distance += diff;
        }
    }
    cout << distance;
}
