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
    while (true)
    {
        int N;
        cin >> N;
        if (N == 0) break;
        vector<vector<int>> words(N, vector<int>(27, 0));
        vector<int> tiles(27, 0);
        for (int i = 0; i < N; i++)
        {
            string word;
            cin >> word;
            for (int j = 0; j < word.size(); j++)
            {
                if (word[j] == 95)
                {
                    words[i][0] += 1;
                }
                else
                {
                    words[i][word[j] - 64] += 1;
                }
            }
        }
        string tile;
        cin >> tile;
        for (int j = 0; j < tile.size(); j++)
        {
            if (tile[j] == 95)
            {
                tiles[0] += 1;
            }
            else
            {
                tiles[tile[j] - 64] += 1;
            }
        }
        
        int count = 0;
        for (int i = 0; i < N; i++)
        {

            int blank = 0;
            
            for (int j = 1; j < 27; j++)
            {
                //cout << i << ": " << j << ", " << words[i][j] << ", " << tiles[j] << "\n";
                if (words[i][j] > tiles[j])
                {
                    blank += words[i][j] - tiles[j];
                }
            }
         
            if (blank <= tiles[0]) count += 1;
        }
        cout << count << "\n";
    }
}
