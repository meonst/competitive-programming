#include <string>
#include <iomanip>
#include <utility>
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <stdint.h>
#include <inttypes.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <unordered_map>
#include <numeric>
#include <algorithm>
using namespace std;

int N, half;
vector<vector<int>> dots;
vector<int> coordinates_x;
vector<int> coordinates_y;

bool dot_is_in_square(int X, int Y, int max_X, int max_Y, int min_X, int min_Y)
{
    if (X >= min_X && X <= max_X && Y >= min_Y && Y <= max_Y)
        return true;
    return false;
}

bool enough_dots_in_square(int max_X, int max_Y, int min_X, int min_Y)
{
    int count = N;
    for (int i = 0; i < N; i++)
    {
        if (dot_is_in_square(dots[i][0], dots[i][1], max_X, max_Y, min_X, min_Y))
        {
            count -= 1;
            if (count < half) break;
        }
    }
    return count >= half;
}

int area_of_square(int max_X, int max_Y, int min_X, int min_Y)
{
    return (max_X - min_X + 2) * (max_Y - min_Y + 2);
}

bool enough_dots(int i, int j, int k, int l)
{
    return ((j + l - i - k + 2) >= half);
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    half = N / 2;
    for (int i = 0; i < N; i++)
    {
        vector<int> a(2);
        cin >> a[0] >> a[1];
        dots.push_back(a);
        coordinates_x.push_back(a[0]);
        coordinates_y.push_back(a[1]);
    }
    sort(coordinates_x.begin(), coordinates_x.end());
    sort(coordinates_y.begin(), coordinates_y.end());


    int minimum_area = 1000000000;


    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            for (int k = 0; k < N - 1; k++)
            {
                for (int l = k + 1; l < N; l++)
                {
                    if (enough_dots(i, j, k, l))
                    {
                        if (area_of_square(coordinates_x[j], coordinates_y[l], coordinates_x[i], coordinates_y[k]) < minimum_area)
                        {
                            if (enough_dots_in_square(coordinates_x[j], coordinates_y[l], coordinates_x[i], coordinates_y[k]))
                            {
                                minimum_area = area_of_square(coordinates_x[j], coordinates_y[l], coordinates_x[i], coordinates_y[k]);
                            }
                        }
                    }
                }
            }
        }
    }
    cout << minimum_area;
}
