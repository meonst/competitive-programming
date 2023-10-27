#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cout.precision(10);
    cin.tie(NULL);
    cout.tie(NULL);
    double x1, x2, x3, x4, y1, y2, y3, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    double A1 = y2 - y1;
    double B1 = x1 - x2;
    double C1 = y1 * x2 - x1 * y2;
    // 첫 직선: A1 * x + B1 * y + C1 = 0

    double A2 = y4 - y3;
    double B2 = x3 - x4;
    double C2 = y3 * x4 - x3 * y4;
    // 첫 직선: A2 * x + B2 * y + C2 = 0
    double not_parallel = B1 * A2 - A1 * B2;
    bool intersect = false;
    double x = C1 * B2 - B1 * C2;
    double y = A1 * C2 - C1 * A2;
    if (not_parallel)
    {
        double X = x / not_parallel;
        double Y = y / not_parallel;
        // 교점 = (x / not_parallel, y / not_parallel);
        // cout << x << ", " << y << ", " << not_parallel << "\n";
        // cout << X << ", " << Y << "\n";
        if (
            min(x1, x2) <= X && X <= max(x1, x2) &&
            min(x3, x4) <= X && X <= max(x3, x4) &&
            min(y1, y2) <= Y && Y <= max(y1, y2) &&
            min(y3, y4) <= Y && Y <= max(y3, y4) 
        )
        {
            intersect = true;
            cout << "1\n" << X << " " << Y;
        }
    }
    else  // 평행
    {
        //cout << C1 << ", " << C2 << ", " << B1 << ", " << B2 << ", " << x << ", " << y << "\n";
        if (C1 * B2 == B1 * C2) // 동일 선분
        {
            int minX1 = min(x1, x2);
            int maxX1 = max(x1, x2);
            int minX2 = min(x3, x4);
            int maxX2 = max(x3, x4);
                        
            int minY1 = min(y1, y2);
            int maxY1 = max(y1, y2);
            int minY2 = min(y3, y4);
            int maxY2 = max(y3, y4);

            if (
                (
                    (minX2 <= minX1 && minX1 <= maxX2) ||
                    (minX2 <= maxX1 && maxX1 <= maxX2) ||
                    (minX1 <= minX2 && minX2 <= maxX1) ||
                    (minX1 <= maxX2 && maxX2 <= maxX1)) &&
                (
                    (minY2 <= minY1 && minY1 <= maxY2) ||
                    (minY2 <= maxY1 && maxY1 <= maxY2) ||
                    (minY1 <= minY2 && minY2 <= maxY1) ||
                    (minY1 <= maxY2 && maxY2 <= maxY1)
                    )
            )
            {
                intersect = true;
                cout << 1 << "\n";
                if (x1 == x3 && y1 == y3)
                {
                    if ((x1 - x2) * (x1 - x4) <= 0 && (y1 - y2) * (y1 - y4) <= 0)
                    {
                        cout << x1 << " " << y1;
                    }
                }
                if (x1 == x4 && y1 == y4)
                {
                    if ((x1 - x2) * (x1 - x3) <= 0 && (y1 - y2) * (y1 - y3) <= 0)
                    {
                        cout << x1 << " " << y1;
                    }
                }
                if (x2 == x3 && y2 == y3)
                {
                    if ((x2 - x1) * (x2 - x4) <= 0 && (y2 - y1) * (y2 - y4) <= 0)
                    {
                        cout << x2 << " " << y2;
                    }
                }
                if (x2 == x4 && y2 == y4)
                {
                    if ((x2 - x1) * (x2 - x3) <= 0 && (y2 - y1) * (y2 - y3) <= 0)
                    {
                        cout << x2 << " " << y2;
                    }
                }
            }
        }
    }
    if (!intersect) cout << 0;
}
