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

vector<vector<int>> board(19, vector<int>(19, 0));

int get(int row, int column)
{
    if (row >= 0 && row <= 18 && column >= 0 && column <= 18) return board[row][column];
    return 0;
}

bool victory_45(int row, int column)
{
    int start = board[row][column];
    bool victory =
        start != get(row + 1, column - 1) &&
        start == get(row - 1, column + 1) &&
        start == get(row - 2, column + 2) &&
        start == get(row - 3, column + 3) &&
        start == get(row - 4, column + 4) &&
        start != get(row - 5, column + 5);
    return victory;
}
bool victory_90(int row, int column)
{
    int start = get(row, column);
    bool victory =
        start != get(row, column - 1) &&
        start == get(row, column + 1) &&
        start == get(row, column + 2) &&
        start == get(row, column + 3) &&
        start == get(row, column + 4) &&
        start != get(row, column + 5);
    return victory;
}
bool victory_135(int row, int column)
{
    int start = board[row][column];
    bool victory =
        start != get(row - 1, column - 1) &&
        start == get(row + 1, column + 1) &&
        start == get(row + 2, column + 2) &&
        start == get(row + 3, column + 3) &&
        start == get(row + 4, column + 4) &&
        start != get(row + 5, column + 5);
    return victory;
}
bool victory_180(int row, int column)
{
    int start = board[row][column];
    bool victory =
        start != get(row - 1, column) &&
        start == get(row + 1, column) &&
        start == get(row + 2, column) &&
        start == get(row + 3, column) &&
        start == get(row + 4, column) &&
        start != get(row + 5, column);
    return victory;
}

bool victorious(int row, int column)
{
    bool victory = victory_45(row, column) || victory_90(row, column) || victory_135(row, column) || victory_180(row, column);
    return victory;
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 19; i++)
    {
        for (int j = 0; j < 19; j++)
        {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < 19; i++)
    {
        for (int j = 0; j < 19; j++)
        {
            if (board[i][j] == 0)
                continue;
            if (victorious(i, j))
            {
                cout << board[i][j] << "\n"
                     << i + 1 << " " << j + 1;
                return 0;
            }
        }
    }
    cout << 0;
}
