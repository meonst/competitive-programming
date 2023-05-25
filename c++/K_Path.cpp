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
#include <regex>
#include <stdio.h>
#include <stdlib.h>
#include <cassert>
#include <queue>
using namespace std;
typedef long long ll;

ll modulo = 1000000007;

vector<vector<ll>> matrix_product(vector<vector<ll>> matrix1, vector<vector<ll>> matrix2)
{
    ll common = matrix1[0].size();
    ll row = matrix1.size();
    ll column = matrix2.size();
    vector<vector<ll>> p(row, vector<ll>(column, 0));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            for (int k = 0; k < common; k++)
            {
                p[i][j] += matrix1[i][k] * matrix2[k][j];
                p[i][j] %= modulo;
            }
        }
    }
    return p;
}

vector<vector<ll>> matrix_square(vector<vector<ll>> matrix)
{
    return matrix_product(matrix, matrix);
}

vector<vector<ll>> matrix_power(vector<vector<ll>> matrix, ll n)
{
    if (n == 1)
    {
        return matrix;
    }
    if (n == 2)
    {
        return matrix_square(matrix);
    }
    else if (n % 2 == 0)
    {
        return matrix_square(matrix_power(matrix, n / 2));
    }
    else
    {
        return matrix_product(matrix_square(matrix_power(matrix, n / 2)), matrix);
    }
}

void matrix_print(vector<vector<ll>> matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}


int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, K;
    cin >> N >> K;
    vector<vector<ll>> road(N, vector<ll>(N));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> road[i][j];
        }
    }
    vector<vector<ll>> answer = matrix_power(road, K);
    ll ans = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            ans += answer[i][j];
            ans %= modulo;
        }
    }
    cout << ans;
}
