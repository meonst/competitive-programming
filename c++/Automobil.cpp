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
typedef unsigned long long ull;
ull modulo = 1000000007;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M, K;
    cin >> N >> M >> K;
    
    vector<ull> row(N + 1, 1);
    vector<ull> column(M + 1, 1);
    for (int i = 0; i < K; i++)
    {
        string a;
        int b, c;
        cin >> a >> b >> c;
        
        if (a == "R")
        {
            row[b] = (row[b] * c) % modulo;
        }
        else 
        {
            column[b] = (column[b] * c) % modulo;
        }
    }

    ull sum = 0;
    ull column_sum = 0;
    ull column_multiplied_sum = 0;
    
    
    for (int i = 1; i <= M; i++)
    {
        column_sum += column[i];
        column_multiplied_sum += i * column[i];

        column_sum %= modulo;
        column_multiplied_sum %= modulo;
    }

    
    for (int i = 1; i <= N; i++)
    {
        ull row_sum = 0;
        row_sum += (((i - 1) * M % modulo) * column_sum) % modulo;
        row_sum %= modulo;

        row_sum += column_multiplied_sum;
        row_sum %= modulo;

        row_sum *= row[i];
        row_sum %= modulo;
        sum += row_sum;
        sum %= modulo;
    }
    cout << sum;

}

