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
    int sum = 0;
    unordered_map<string, int> scolville;
    scolville["Poblano"] = 1500;
    scolville["Mirasol"] = 6000;
    scolville["Serrano"] = 15500;
    scolville["Cayenne"] = 40000;
    scolville["Thai"] = 75000;
    scolville["Habanero"] = 125000;

    for (int i = 0; i < n; i++)
    {
        string spice;
        cin >> spice;
        sum += scolville[spice];
    }
    cout << sum;
}
