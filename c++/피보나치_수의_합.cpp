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
ll modulo = 1000000000;
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

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll a, b;
    cin >> a >> b;
    vector<vector<ll>> fib(2, vector<ll>(2, 1));
    fib[0][0] = 0;
    vector<vector<ll>> matrix1 = matrix_power(fib, a);
    vector<vector<ll>> matrix2 = matrix_power(fib, b + 1);

    cout << ((matrix2[0][0] + matrix2[0][1]) - (matrix1[0][0] + matrix1[0][1]) + modulo) % modulo;
}
