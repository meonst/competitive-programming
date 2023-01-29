
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

vector<int> sudoku(81, 0);
vector<int> zero_position;
int zero_count = -1;
vector<int> tbt_table{
    0, 0, 0, 3, 3, 3, 6, 6, 6,
    0, 0, 0, 3, 3, 3, 6, 6, 6,
    0, 0, 0, 3, 3, 3, 6, 6, 6,
    27, 27, 27, 30, 30, 30, 33, 33, 33,
    27, 27, 27, 30, 30, 30, 33, 33, 33,
    27, 27, 27, 30, 30, 30, 33, 33, 33,
    54, 54, 54, 57, 57, 57, 60, 60, 60,
    54, 54, 54, 57, 57, 57, 60, 60, 60,
    54, 54, 54, 57, 57, 57, 60, 60, 60};

vector<int> hori{
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    9, 9, 9, 9, 9, 9, 9, 9, 9,
    18, 18, 18, 18, 18, 18, 18, 18, 18,
    27, 27, 27, 27, 27, 27, 27, 27, 27,
    36, 36, 36, 36, 36, 36, 36, 36, 36,
    45, 45, 45, 45, 45, 45, 45, 45, 45,
    54, 54, 54, 54, 54, 54, 54, 54, 54,
    63, 63, 63, 63, 63, 63, 63, 63, 63,
    72, 72, 72, 72, 72, 72, 72, 72, 72};

vector<int> tbt{0, 1, 2, 9, 10, 11, 18, 19, 20};

bool backtrack(int last)
{
    bool answer = false;
    int position = zero_position[last];
    vector<bool> vertical(10, true);
    vector<bool> horizontal(10, true);
    vector<bool> three_by_three(10, true);

    for (int i = position % 9; i < 81; i += 9)
    {
        vertical[sudoku[i]] = false;
    }
    for (int i = hori[position]; i < hori[position] + 9; i++)
    {
        horizontal[sudoku[i]] = false;
    }
    for (int i = 0; i < 9; i += 1)
    {
        three_by_three[sudoku[tbt_table[position] + tbt[i]]] = false;
    }

    for (int i = 1; i < 10; i++)
    {
        if (vertical[i] && horizontal[i] && three_by_three[i])
        {
            sudoku[zero_position[last]] = i;
            // cout << i << " " << last << "\n";
            if (last == zero_count)
            {
                answer = true;
                break;
            }
            else
            {
                if (backtrack(last + 1))
                {
                    answer = true;
                    break;
                }
            }
        }
    }
    if (!answer)
    {
        sudoku[zero_position[last]] = 0;
    }
    return answer;
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 81; i++)
    {
        cin >> sudoku[i];
        if (sudoku[i] == 0)
        {
            zero_position.push_back(i);
            zero_count += 1;
        }
    }

    backtrack(0);

    for (int i = 0; i < 81; i++)
    {
        cout << sudoku[i] << " ";
        if (i % 9 == 8)
            cout << "\n";
    }
}
