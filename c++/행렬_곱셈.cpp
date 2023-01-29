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


int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b, c, d;
    cin >> a >> b;
    vector<vector<int>> first_matrix(a, vector<int>(b, 0));
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            cin >> first_matrix[i][j];
        }
    }


    cin >> c >> d;
    vector<vector<int>> second_matrix(c, vector<int>(d, 0));

    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < d; j++)
        {
            cin >> second_matrix[i][j];
        }
    }

    vector<vector<int>> product(a, vector<int>(d, 0));
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < d; j++)
        {
            for (int k = 0; k < b; k++)
            {
                product[i][j] += first_matrix[i][k] * second_matrix[k][j];
            }
            cout << product[i][j] << " ";
        }
        cout << "\n";
    }
    
}
