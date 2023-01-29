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
    vector<int> country(N, 0);
    vector<int> student(N, 0);
    vector<int> score(N, 0);
    vector<int> country_win_count(N, 0);          
    int first = -1;
    int second = -2;                                      
    for (int i = 0; i < N; i++)
    {
        cin >> country[i] >> student[i] >> score[i];
    }
    for (int j = 0; j < 3; j++)
    {
        int highest = 0;
        int high = 0;
        for (int i = 0; i < N; i++)
        {
            if (high < score[i])
            {
                if (j == 2 && first == second && second == country[i]) continue;
                high = score[i];
                highest = i;
            }
        }
        if (j == 0) first = country[highest];
        if (j == 1) second = country[highest];
        cout << country[highest] << " " << student[highest] << "\n";
        score[highest] = 0;
    }
}
