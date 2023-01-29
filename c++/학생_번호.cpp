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
    vector<string> student(N);
    for (int i = 0; i < N; i++) cin >> student[i];
    int count = 0;
    bool cont = true;
    while (cont)
    {
        count += 1;
        unordered_map<string, int> stud;
        for (int i = 0; i < N; i++)
        {
            string substring = student[i].substr(student[i].length() - count, count);
            if (stud.find(substring) == stud.end())
            {
                stud[substring] = 1;
                if (i == N - 1)
                {
                    cont = false;
                }
            }
            else break;
        }
    }


    cout << count;


}
