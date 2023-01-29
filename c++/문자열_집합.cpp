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

using namespace std;

int main()
{
    int N;
    int M;
    int count = 0;
    cin >> N >> M;

    map<string, int> words;
    for (int i = 0; i < N; i++) 
    {
        string word;
        cin >> word;
        words.insert({word, 1});
    }

    string word;
    for (int i = 0; i < M; i++)
    {
        cin >> word;
        if (words[word]) count += 1;
    }
    printf("%d", count);
}
