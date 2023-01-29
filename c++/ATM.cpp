
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

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    vector<int> atm(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> atm[i];
    }
    sort(atm.begin(), atm.end());
    int time = 0;
    for (int i = 0; i < N; i++)
    {
        time += atm[i] * (N - i);
    }
    cout << time;
}
