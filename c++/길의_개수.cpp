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
ll modulo = 1000003;

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
    ll N, S, E, T;
    cin >> N >> S >> E >> T;
    // 0 -> 4 moves left
    // 1 -> 3 moves left
    // 2 -> 2 moves left
    // 3 -> 1 move left
    // 4 -> arrived
    
    vector<vector<ll>> answer(1, vector<ll>(N * 5, 0));
    answer[0][(S - 1) * 5 + 4] = 1;
    vector<vector<ll>> extended_map(N * 5, vector<ll>(N * 5, 0));

    for (int i = 0; i < N; i++)
    {
        string in;
        cin >> in;
        for (int j = 0; j < N; j++)
        {
            int moves = 5 - (in[j] - '0');
            if (moves == 5) continue;
            //cout << "here: " << i * 5 + moves << ", " << j * 5 + 4 << "\n";
            extended_map[i * 5 + 4][j * 5 + moves] = 1;
        }
    }
    

    for (int i = 0; i < N; i++)
    {
        for (int j = i * 5 + 1; j < i * 5 + 5; j++)
        {
            extended_map[j - 1][j] = 1;
        }
    }
    // cout << "extended map\n";
    // matrix_print(extended_map);

    // cout << 0 << "\n";
    // matrix_print(answer);

    answer = matrix_product(answer, matrix_power(extended_map, T));

    // cout << "answer\n";
    // matrix_print(answer);
    cout << answer[0][(E - 1) * 5 + 4];
}
