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


int odd_maximum = -1;
int even_maximum = -1;
int board_size;
vector<vector<int>> odd_board;
vector<vector<int>> odd_available;
vector<vector<int>> even_board;
vector<vector<int>> even_available;
int r, c;

vector<vector<int>> fill(vector<vector<int>> board, int row, int column)
{
    for (int i = 0; i < board_size - max(row, column); i++)
    {
        board[row + i][column + i] = 0;
    }

    for (int i = 0; i < min(board_size - row, column + 1); i++)
    {
        board[row + i][column - i] = 0;
    }

    for (int i = 0; i <= min(row, column); i++)
    {
        board[row - i][column - i] = 0;
    }

    for (int i = 0; i < min(row + 1, board_size - column); i++)
    {
        board[row - i][column + i] = 0;
    }

    return board;
}

void even_dfs(int position, int placed_count, vector<vector<int>> board)
{
    if (position >= even_available.size())
    {
        even_maximum = max(even_maximum, placed_count);
        return;
    }

    if (board[even_available[position][0]][even_available[position][1]])
    {
        even_dfs(position + 1, placed_count + 1, fill(board, even_available[position][0], even_available[position][1]));
    }
    even_dfs(position + 1, placed_count, board);
}


void odd_dfs(int position, int placed_count, vector<vector<int>> board)
{
    if (position >= odd_available.size())
    {
        odd_maximum = max(odd_maximum, placed_count);
        return;
    }

    if (board[odd_available[position][0]][odd_available[position][1]])
    {
        odd_dfs(position + 1, placed_count + 1, fill(board, odd_available[position][0], odd_available[position][1]));
    }
    odd_dfs(position + 1, placed_count, board);
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> board_size;
    int x;
    for (int i = 0; i < board_size; i++)
    {
        vector<int> odd_row(board_size, 0);
        vector<int> even_row(board_size, 0);
        for (int j = 0; j < board_size; j++)
        {
            cin >> x;
            if (x)
            {
                if ((i + j) % 2 == 0)
                {
                    even_row[j] = 1;
                    even_available.push_back(vector<int> {i, j});
                }
                else
                {
                    odd_row[j] = 1;
                    odd_available.push_back(vector<int> {i, j});
                }
            }
        }
        even_board.push_back(even_row);
        odd_board.push_back(odd_row);
    }
    even_dfs(0, 0, even_board);
    odd_dfs(0, 0, odd_board);
    cout << even_maximum + odd_maximum;
}

