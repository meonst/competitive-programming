#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cout << fixed << showpoint;
    cout << setprecision(10);
    double area;
    cin >> area;
    double pi = atan(1) * 4;
    // pi * r * r = area
    // we want 2 * pi * r
    double r = pow(area / pi, 0.5);
    
    
    cout << (2 * r * pi);
}

