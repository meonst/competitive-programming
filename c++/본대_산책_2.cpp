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
    ll D;
    cin >> D;

    //정보과학관, 전산관, 미래관, 신양관, 진리관, 한경직기념관, 학생회관, 형남공학관
    vector<vector<ll>> initial {{1, 0, 0, 0, 0, 0, 0, 0}};
    vector<vector<ll>> product 
    {
        vector<ll> {0, 1, 1, 0, 0, 0, 0, 0}, // 정보과학관
        vector<ll> {1, 0, 1, 1, 0, 0, 0, 0}, // 전산관
        vector<ll> {1, 1, 0, 1, 0, 1, 0, 0}, // 미래관
        vector<ll> {0, 1, 1, 0, 1, 1, 0, 0}, // 신양관
        vector<ll> {0, 0, 0, 1, 0, 1, 1, 0}, // 진리관
        vector<ll> {0, 0, 1, 1, 1, 0, 0, 1}, // 한경직기념관
        vector<ll> {0, 0, 0, 0, 1, 0, 0, 1}, // 학생회관
        vector<ll> {0, 0, 0, 0, 0, 1, 1, 0}  // 형남공학관
    };
    vector<vector<ll>> a = matrix_product(initial, matrix_power(product, D));
    cout << a[0][0];
}
