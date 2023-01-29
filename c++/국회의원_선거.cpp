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
    vector<int> votes(N);
    for (int i = 0; i < N; i++) cin >> votes[i];

    int bribe = 0;
    int max;
    int max_person;
    while (true)
    {
        max = votes[0];
        max_person = 0;
        for (int i = 1; i < N; i++)
        {
            if (votes[i] >= max)
            {
                max = votes[i];
                max_person = i;
            }
        }
        if (max_person == 0) break;
        votes[max_person] -= 1;
        votes[0] += 1;
        bribe += 1;
    }
    cout << bribe;


}
