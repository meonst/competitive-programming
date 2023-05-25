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
vector<vector<ll>> matrix_product(const vector<vector<ll>> &matrix1, const vector<vector<ll>> &matrix2)
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

vector<vector<ll>> matrix_square(const vector<vector<ll>> &matrix)
{
    return matrix_product(matrix, matrix);
}

vector<vector<ll>> matrix_power(const vector<vector<ll>> &matrix, ll n)
{
    if (n == 1)
    {
        return matrix;
    }
    if (n == 2)
    {
        return matrix_square(matrix);
    }
    if (n % 2 == 0)
    {
        return matrix_square(matrix_power(matrix, n / 2));
    }
    return matrix_product(matrix_square(matrix_power(matrix, n / 2)), matrix);
    
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll N, B;
    cin >> N >> B;
    vector<vector<ll>> combination(1, vector<ll>(B, 1));
    combination[0][B - 1] = 2;

    vector<vector<ll>> step(B, vector<ll>(B, 0));
    for (int i = 0; i < B - 1; i++)
    {
        step[i + 1][i] = 1;
    }
    step[0][B - 1] = 1;
    step[B - 1][B - 1] = 1;
    if (N > B)
    {
        vector<vector<ll>> answer = matrix_product(combination, matrix_power(step, N - B));
        cout << answer[0][B - 1];
    }
    else
    {
        cout << combination[0][N - 1];
    }


}

