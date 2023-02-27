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
    int N;
    cin >> N;
    vector<int> alphabets(26, 0);

    string word;
    for (int i = 0; i < N; i++)
    {
        cin >> word;
        for (int j = 0; j < word.size(); j++)
        {
            alphabets[word[j] - 65] += pow(10, word.size() - j - 1);
        }
    }

    sort(alphabets.begin(), alphabets.end());
    int sum = 0;
    for (int i = 9; i > 0; i--)
    {
        sum += alphabets[16 + i] * i; 
    }
    cout << sum;
}
