
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
    int n;
    int input;
    cin >> n;
    vector<int> plates(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        plates[i] = input;
    }
    sort(plates.begin(), plates.end());
    int common = plates[1] - plates[0];
    for (int i = 2; i < n; i++)
    {
        common = gcd(common, plates[i] - plates[i - 1]);
    }
    vector<int> answer;
    for (int i = 2; pow(i, 2) <= common; i++)
    {
        if (common % i == 0)
        {
            answer.push_back(i);
            if (i != common / i) answer.push_back(common / i);
        }
    }
    
    sort(answer.begin(), answer.end());
    answer.push_back(common);
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << " ";
    }
}
