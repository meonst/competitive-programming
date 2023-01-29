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

vector<int> primes;
int first_prime, second_prime;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    int max_second = N;
    int temp;
    int max_count = -1;
    int before, before2;
    for (int i = 1; i <= N; i++)
    {
        int count = 1;
        
        before = i;
        before2 = N;
        while (before >= 0)
        {
            count += 1;
            temp = before2;
            before2 = before;
            before = temp - before;
        }
        if (count > max_count)
        {
            max_count = count;
            max_second = i;
        }
    }
    cout << max_count << "\n";
    before2 = N;
    before = max_second;
    cout << before2 << " ";
    while (before >= 0)
    {
        cout << before << " ";
        temp = before2;
        before2 = before;
        before = temp - before;
    }
}
