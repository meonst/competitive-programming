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
    vector<int> balls(N);
    for (int i = 0; i < N; i++)
    {
        balls[i] = i + 1;
    }
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        a -= 1;
        b -= 1;
        int temp = balls[a];
        balls[a] = balls[b];
        balls[b] = temp;
    }
    for (int i = 0; i < N; i++)
    {
        cout << balls[i] << " ";
    }
}
