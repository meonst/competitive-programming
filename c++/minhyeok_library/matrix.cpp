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
using namespace std;

typedef long long ll;
ll modulo = 1000;

vector<vector<ll>> matrix_sum(vector<vector<ll>> matrix1, vector<vector<ll>> matrix2)
{
    ll row = matrix1.size();
    ll column = matrix1[0].size();

    vector<vector<ll>> p(row, vector<ll>(column, 0));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            p[i][j] = (matrix1[i][j] + matrix2[i][j]); // % modulo;
        }
    }
    return p;
}

vector<vector<ll>> matrix_product(vector<vector<ll>> matrix1, vector<vector<ll>> matrix2)
{
    ll common = matrix1.size();
    ll row = matrix1[0].size();
    ll column = matrix2.size();
    vector<vector<ll>> p(row, vector<ll>(column, 0));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            for (int k = 0; k < common; k++)
            {
                p[i][j] += matrix1[i][k] * matrix2[k][j];
                //p[i][j] %= modulo;
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
// acmicpc 13246번 참조
vector<vector<ll>> matrix_power_sum(vector<vector<ll>> matrix, ll N)
{
    if (N == 1)
    {
        return matrix;
    }
    else if (N == 2)
    {
        return matrix_sum(matrix, matrix_square(matrix));
    }
    else if (N % 2 == 0)
    {
        return matrix_product(matrix_power_sum(matrix, (N / 2)), matrix_sum(matrix_power(matrix, (N / 2)), I));
    }
    else
    {
        return matrix_sum(matrix_product(matrix_power_sum(matrix, ((N - 1) / 2)), matrix_sum(matrix_power(matrix, ((N - 1) / 2)), I)), matrix_power(matrix, N));
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