#include <bits/stdc++.h>
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
    ll K, N;
    cin >> K >> N;

    //if there is only 1 strip
    vector<vector<ll>> initial(1,vector<ll>(K, 1));


    vector<vector<ll>> another_strip(K, vector<ll>(K, 0));

    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j < K; j++)
        {
            if (gcd(i + 1, j + 1) == 1)
            {
                another_strip[i][j] = 1;
            }
        }
    }
    
    vector<vector<ll>> final = matrix_product(initial, matrix_power(another_strip, N));
    
    cout << final[0][0];
}
