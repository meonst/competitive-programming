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

int N;
vector<int> first_sums;
vector<int> second_sums;
vector<int> first_half;
vector<int> second_half;
bool bigger(int a, int b)
{
    return a > b;
}
void first_dfs(int index, int sum)
{
    if (index >= first_half.size())
    {
        first_sums.push_back(sum);
        return;
    }
    first_dfs(index + 1, sum + first_half[index]);
    first_dfs(index + 1, sum);
}

void second_dfs(int index, int sum)
{
    if (index >= second_half.size())
    {
        second_sums.push_back(sum);
        return;
    }
    second_dfs(index + 1, sum + second_half[index]);
    second_dfs(index + 1, sum);
}


int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int S, x;
    cin >> N >> S;
    for (int i = 0; i < N / 2; i++)
    {
        cin >> x;
        first_half.push_back(x);
    }
    for (int i = 0; i < N - (N / 2); i++)
    {
        cin >> x;
        second_half.push_back(x);
    }
    first_dfs(0, 0);
    second_dfs(0, 0);
    sort(first_sums.begin(), first_sums.end());
    sort(second_sums.begin(), second_sums.end(), bigger);





    // for (int i = 0; i < first_sums.size(); i++)
    // {
    //     cout << first_sums[i] << " ";
    // }
    // cout << "\n";
    // for (int i = 0; i < second_sums.size(); i++)
    // {
    //     cout << second_sums[i] << " ";
    // }
    // cout << "\n";

    int i = 0;
    int j = 0;
    ll c = 0;
    int diff = S - first_sums[i];
    ll in_case_duplicate = 0;
    while (i < first_sums.size())
    {
        if (j == second_sums.size())
        {
            i += 1;
            if (i < first_sums.size() && first_sums[i] == first_sums[i - 1])
            {
                //cout << "here2!, " << in_case_duplicate << "\n";
                c += in_case_duplicate;
            }
            else
            {
                in_case_duplicate = 0;
            }
        }
        else if (second_sums[j] == diff)
        {
            in_case_duplicate += 1;
            c += 1;
            j += 1;
        }
        else if (second_sums[j] < diff)
        {
            i += 1;
            diff = S - first_sums[i];
            if (i < first_sums.size() && first_sums[i] == first_sums[i - 1])
            {
                //cout << "here!, " << in_case_duplicate << "\n";
                c += in_case_duplicate;
            }
            else
            {
                in_case_duplicate = 0;
            }
        }
        else if (diff < second_sums[j])
        {
            j += 1;
        }
    }
    if (S == 0) c -= 1;
    cout << c;
    
}

