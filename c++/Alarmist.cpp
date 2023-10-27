#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int K;
    cin >> K;

    for (int k = 0; k < K; k++)
    {

        int n, w;
        cin >> n >> w;
        int mini = 1231;
        int maxi = -1;
        vector<int> samples(n);
        for (int i = 0; i < n; i++)
        {
            cin >> samples[i];
        }
        for (int i = 0; i < n - w + 1; i++)
        {
            int sum = 0;
            for (int j = i; j < i + w; j++)
            {
                sum += samples[j];
            }
            sum = sum / w;
            
            if (mini > sum) mini = sum;
            if (maxi < sum) maxi = sum;
        }
        cout << "Data Set " << k + 1 << ":\n" << maxi - mini << "\n\n";
    }
}
