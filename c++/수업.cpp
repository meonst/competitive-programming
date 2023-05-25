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

bool sort_by_height(pair<int, int> a, pair<int, int> b)
{
    return a.first > b.first;
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    vector<pair<int, int>> students(N, pair<int, int>());
    for (int i = 0; i < N; i++)
    {
        cin >> students[i].first >> students[i].second;
    }
    sort(students.begin(), students.end(), sort_by_height);

    vector<int> answer{0};

    for (int i = 0; i < N; i++)
    {
        bool done = false;
        if (answer[0] < students[i].second)
        {
            answer[0] += 1;
        }
        else if (answer[answer.size() - 1] >= students[i].second)
        {
            answer.push_back(1);
        }
        else
        {
            int mid;
            int start = 0;
            int end = answer.size() - 1;
            while (start < end)
            {
                mid = (start + end) / 2;
                if (answer[mid] >= students[i].second)
                {
                    start = mid + 1;
                }
                else
                {
                    end = mid;
                }
            }
            answer[end] += 1;
        }
    }
    cout << answer.size();
}
