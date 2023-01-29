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

vector<vector<int>> chess(8, vector<int>(8, 0));
vector<vector<int>> board(8, vector<int>(8, 0));

bool in_board(int row, int column)
{
    if (row >= 0 && row <= 7 && column >= 0 && column <= 7)
        return true;
    else
        return false;
}
void unsafe(int row, int column)
{
    if (in_board(row, column)) chess[row][column] += 1;
}
bool filled(int row, int column)
{
    if (in_board(row, column))
    {
        if (board[row][column] == 1) return true;
    }
    return false;
}
void bishop(int row, int column)
{
    for (int i = 1; i < 8; i++)
    {
        if (filled(row + i, column + i)) break;
        unsafe(row + i, column + i);
    }
    for (int i = 1; i < 8; i++)
    {
        if (filled(row - i, column - i)) break;
        unsafe(row - i, column - i);
    }
    for (int i = 1; i < 8; i++)
    {
        if (filled(row - i, column + i)) break;
        unsafe(row - i, column + i);
    }
    for (int i = 1; i < 8; i++)
    {
        if (filled(row + i, column - i)) break;
        unsafe(row + i, column - i);
    }
}

void rook(int row, int column)
{
    for (int i = 1; i < 8; i++)
    {
        if (filled(row + i, column)) break;
        unsafe(row + i, column);
    }
    for (int i = 1; i < 8; i++)
    {
        if (filled(row - i, column)) break;
        unsafe(row - i, column);
    }
    for (int i = 1; i < 8; i++)
    {
        if (filled(row, column + i)) break;
        unsafe(row, column + i);
    }
    for (int i = 1; i < 8; i++)
    {
        if (filled(row, column - i)) break;
        unsafe(row, column - i);
    }
}

void knight(int row, int column)
{
    unsafe(row + 2, column + 1);
    unsafe(row + 2, column - 1);
    unsafe(row - 2, column + 1);
    unsafe(row - 2, column - 1);
    unsafe(row + 1, column + 2);
    unsafe(row - 1, column + 2);
    unsafe(row + 1, column - 2);
    unsafe(row - 1, column - 2);
}

void queen(int row, int column)
{
    bishop(row, column);
    rook(row, column);
}

void king(int row, int column)
{
    unsafe(row + 1, column + 1);
    unsafe(row + 1, column - 1);
    unsafe(row - 1, column + 1);
    unsafe(row - 1, column - 1);
    unsafe(row, column + 1);
    unsafe(row, column - 1);
    unsafe(row - 1, column);
    unsafe(row + 1, column);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true)
    {
        string input;
        getline(cin, input);
        if (input.empty())
            break;
        int row = 0;
        int column = 0;
        for (int i = 0; i < input.length(); i++)
        {
            if (input[i] == '/')
            {
                column = 0;
                row += 1;
            }
            else if (input[i] == '1')
                column += 1;
            else if (input[i] == '2')
                column += 2;
            else if (input[i] == '3')
                column += 3;
            else if (input[i] == '4')
                column += 4;
            else if (input[i] == '5')
                column += 5;
            else if (input[i] == '6')
                column += 6;
            else if (input[i] == '7')
                column += 7;
            else if (input[i] == '8')
                column += 8;
            else
            {
                board[row][column] = 1;
                chess[row][column] = 1;
                column += 1;
            }
        }
        for (int i = 0; i < input.length(); i++)
        {
            
            int row = 0;
            int column = 0;
            for (int i = 0; i < input.length(); i++)
            {
                if (input[i] == '/')
                {
                    row += 1;
                    column = 0;
                }
                else if (input[i] == '1')
                    column += 1;
                else if (input[i] == '2')
                    column += 2;
                else if (input[i] == '3')
                    column += 3;
                else if (input[i] == '4')
                    column += 4;
                else if (input[i] == '5')
                    column += 5;
                else if (input[i] == '6')
                    column += 6;
                else if (input[i] == '7')
                    column += 7;
                else if (input[i] == '8')
                    column += 8;
                else
                {
                    if (input[i] == 'P')
                    {
                        unsafe(row - 1, column + 1);
                        unsafe(row - 1, column - 1);
                    }
                    else if (input[i] == 'p')
                    {
                        unsafe(row + 1, column + 1);
                        unsafe(row + 1, column - 1);
                    }
                    else if (input[i] == 'N' || input[i] == 'n')
                    {
                        knight(row, column);
                    }
                    else if (input[i] == 'B' || input[i] == 'b')
                    {
                        bishop(row, column);
                    }
                    else if (input[i] == 'R' || input[i] == 'r')
                    {
                        rook(row, column);
                    }
                    else if (input[i] == 'Q' || input[i] == 'q')
                    {
                        queen(row, column);
                    }
                    else if (input[i] == 'K' || input[i] == 'k')
                    {
                        king(row, column);
                    }
                    column += 1;
                }
            }
        }

        int safe = 0;
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (chess[i][j] == 0)
                    safe += 1;
                // cout << chess[i][j] << ",";
                chess[i][j] = 0;
                board[i][j] = 0;
            }
            // cout << "\n";
        }
        cout << safe << "\n";
    }
}
