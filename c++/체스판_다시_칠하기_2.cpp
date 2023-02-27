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

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<int>> board(N + 1, vector<int>(M + 1, 0));
    string letter;
    for (int i = 1; i <= N; i++)
    {
        int j = 1;

        cin >> letter;
        if ((i + j) % 2 == 0 && letter[j - 1] == 66)
            board[i][j] = 1;
        else if ((i + j) % 2 == 1 && letter[j - 1] == 87)
            board[i][j] = 1;
        else
            board[i][j] = 0;
            
        for (j = 2; j <= M; j++)
        {
            if ((i + j) % 2 == 0 && letter[j - 1] == 66)
                board[i][j] = board[i][j - 1] + 1;
            else if ((i + j) % 2 == 1 && letter[j - 1] == 87)
                board[i][j] = board[i][j - 1] + 1;
            else
                board[i][j] = board[i][j - 1];
        }
    }

    for (int i = 2; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            board[i][j] += board[i - 1][j];
        }
    }


    int minimum = 999999999;
    int sum;
    int square = K * K;
    
    for (int i = 1; i <= N - K + 1; i++)
    {
        for (int j = 1; j <= M - K + 1; j++)
        {
            sum = board[i + K - 1][j + K - 1] - board[i + K - 1][j - 1] - board[i - 1][j + K - 1] + board[i - 1][j - 1];
            
            //cout << sum << " ";
            sum = min(square - sum, sum);
            minimum = min(sum, minimum);
        }
        //cout << "\n";
    }
    cout << minimum;
}
