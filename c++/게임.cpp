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

int N, M;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    vector<string> board(N);
    vector<vector<int>> after(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++)
    {
        cin >> board[i];
    }

    int count = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (board[i][j] == 'H') continue;

            bool u_doom = false;
            bool d_doom = false;
            bool l_doom = false;
            bool r_doom = false;
            int steps = board[i][j] - '0';
            if (i - steps < 0 || board[i - steps][j] == 'H') u_doom = true;
            if (i + steps >= N || board[i + steps][j] == 'H') d_doom = true;
            if (j - steps < 0 || board[i][j - steps] == 'H') l_doom = true;
            if (j + steps >= M || board[i][j + steps] == 'H') r_doom = true;

            if (u_doom && d_doom && l_doom && r_doom)
            {
                after[i][j] = 1;
                count += 1;
            }
        }
    }
    if (count == 0)
    {
        cout << -1;
        return 0;
    }
    for (int loops = 2; loops <= M * N; loops++)
    {
        count = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (after[i][j] != 0) continue;
                if (board[i][j] == 'H') continue;
                bool u_doom = false;
                bool d_doom = false;
                bool l_doom = false;
                bool r_doom = false;
                int steps = board[i][j] - '0';
                if (i - steps < 0 || board[i - steps][j] == 'H' || (after[i - steps][j] != 0 && after[i - steps][j] != loops)) u_doom = true;
                if (i + steps >= N || board[i + steps][j] == 'H' || (after[i + steps][j] != 0 && after[i + steps][j] != loops)) d_doom = true;
                if (j - steps < 0 || board[i][j - steps] == 'H' || (after[i][j - steps] != 0 && after[i][j - steps] != loops)) l_doom = true;
                if (j + steps >= M || board[i][j + steps] == 'H' || (after[i][j + steps] != 0 && after[i][j + steps] != loops)) r_doom = true;

                if (u_doom && d_doom && l_doom && r_doom)
                {
                    after[i][j] = loops;
                    count += 1;
                }
            }
        }
        if (count == 0) break;
        if (after[0][0] != 0) break;
    }
    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < M; j++)
    //     {
    //         cout << after[i][j];
    //     }
    //     cout << "\n";
    // }

    if (after[0][0] != 0) cout << after[0][0];
    else
    {
        if (count == 0) cout << -1;
    }
}
