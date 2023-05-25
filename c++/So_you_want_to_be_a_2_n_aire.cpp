#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while (true)
    {
        int n;
        double t; 
        cin >> n >> t;
        if (n == 0 && t == 0) break;
        double answer;

        if (t >= 0.5)
        {
            answer = pow(1 + t, n);
        }
        else
        {
            double keep_probability = (0.5 - t) / (1 - t);
            double continue_probability = (1 - keep_probability) * 1.5;
            answer = 0;
            for (double i = 0; i < n; i++)
            {
                answer += keep_probability * pow(continue_probability, i);
            }
            answer += pow(continue_probability, n);
        }
        
        printf("%.3lf\n", answer);
    }
    
    
}
