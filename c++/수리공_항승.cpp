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
    int N, L;
    cin >> N >> L;
    vector<int> leak(N);
    for (int i = 0; i < N; i++)
    {
        cin >> leak[i];
    }
    sort(leak.begin(), leak.end());
    int last_tape = leak[0];
    int count = 1;
    for (int i = 1; i < N; i++)
    {
        if (leak[i] - last_tape >= L)
        {
            count += 1;
            last_tape = leak[i];
        }
    }
    cout << count;
}
