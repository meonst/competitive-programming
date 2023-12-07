    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;

    int main()
    {
        ios_base ::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int sun = (-1) * a;
        int moon = (-1) * c;

        while (true)
        {
            if (sun >= moon)
                moon += d;
            else
                sun += b;

            if (sun == moon && sun >= 0 && moon >= 0) break;
        }
        cout << sun;
    }
