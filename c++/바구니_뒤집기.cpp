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
    int N, M;
    cin >> N >> M;
    vector<int> baskets(N);
    for (int i = 1; i <= N; i++)
    {
        baskets[i - 1] = i;
    }
    
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        a -= 1;
        b -= 1;
        vector<int> temp(b - a + 1);
        for (int i = 0; i <= b - a; i++)
        {
            temp[i] = baskets[b - i];
        }
        for (int i = 0; i <= b - a; i++)
        {
            baskets[a + i] = temp[i];
        }
    }

    for (int i = 0; i < N; i++)
    {
        cout << baskets[i] << " ";
    }
}
