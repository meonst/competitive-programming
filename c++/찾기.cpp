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

string T, P;
vector<int> prefix_length;

void get_prefix_length()
{
    prefix_length[0] = 0;
    int length = 0;
    for (int i = 1; i < P.size();)
    {
        if (P[i] == P[length])
        {
            length += 1;
            prefix_length[i] = length;
            i += 1;
        }
        else
        {
            if (length != 0)
            {
                length = prefix_length[length - 1];
            }
            else
            {
                prefix_length[i] = 0;
                i++;
            }
        }
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    getline(cin, T);
    getline(cin, P);
    prefix_length.resize(P.size());
    get_prefix_length();

    vector<int> match;
    int count = 0;

    int index_T = 0;
    int index_P = 0;
    for (index_T; index_T < T.size();)
    {
        // cout << "1: " << index_T << ", " << index_P << "\n";
        // cout << "2: " << T[index_T] << ", " << P[index_P] << "\n";

        if (T[index_T] == P[index_P])
        {
            if (index_P == P.size() - 1)
            {
                match.push_back(index_T - index_P + 1);
                count += 1;
                if (P.size() == 1) 
                {
                    index_T += 1;
                    continue;
                }
                index_P = prefix_length[index_P - 1];
                
            }
            else
            {
                index_T += 1;
                index_P += 1;
            }
        }
        else
        {
            if (index_P != 0)
            {
                // cout << "3: " << prefix_length[index_P - 1] << "\n";
                index_P = prefix_length[index_P - 1];
            }
            else
            {
                index_T += 1;
            }
        }
    }
    // cout << "results\n";
    // cout << T << "\n";
    // cout << P << "\n";
    // for (int i = 0; i < P.size(); i++)
    // {
    //     cout << prefix_length[i];
    // }
    // cout << "\n";
    cout << count << "\n";
    for (int i = 0; i < count; i++)
    {
        cout << match[i] << " ";
    }
}
