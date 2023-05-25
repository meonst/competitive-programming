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

char pattern[20];


vector<ll> control_date(19, 0);
vector<int> days, months, years;
vector<int> days_in_month {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
void get_days()
{
    for (int i = 1; i <= 31; i++)
    {
        if (pattern[0] == 'X')
        {
            if (pattern[1] == 'X')
            {
                days.push_back(i);
                continue;
            }
            else if (i % 10 == pattern[1] - '0')
            {
                days.push_back(i);
                continue;
            }
        }
        else if (pattern[1] == 'X')
        {
            if (pattern[0] - '0' == i / 10)
            {
                days.push_back(i);
                continue;
            }
        }
        else
        {
            if (pattern[0] - '0' == i / 10 && pattern[1] - '0' == i % 10)
            {
                days.push_back(i);
            }
        }
    }
}
void get_months()
{
    for (int i = 1; i <= 12; i++)
    {
        if (pattern[2] == 'X')
        {
            if (pattern[3] == 'X')
            {
                months.push_back(i);
                continue;
            }
            else if (i % 10 == pattern[3] - '0')
            {
                months.push_back(i);
                continue;
            }
        }
        else if (pattern[3] == 'X')
        {
            if (pattern[2] - '0' == i / 10)
            {
                months.push_back(i);
                continue;
            }
        }
        else
        {
            if (pattern[2] - '0' == i / 10 && pattern[3] - '0' == i % 10)
            {
                months.push_back(i);
            }
        }
    }
}
void get_years()
{
    for (int i = 0; i < 10; i++)
        if (pattern[4] == 'X' || pattern[4] - '0' == i)
            for (int j = 0; j < 10; j++)
                if (pattern[5] == 'X' || pattern[5] - '0' == j)
                    for (int k = 0; k < 10; k++)
                        if (pattern[6] == 'X' || pattern[6] - '0' == k)
                            for (int l = 0; l < 10; l++)
                                if (pattern[7] == 'X' || pattern[7] - '0' == l)
                                    if (i + j + k + l != 0)
                                        years.push_back(i * 1000 + j * 100 + k * 10 + l);
}
int last_day_of_month(int year, int month)
{
    if (month != 2) return days_in_month[month];
    else
    {
        if (year % 400 == 0) return 29;
        else if (year % 100 == 0) return 28;
        else if (year % 4 == 0) return 29;
        else return 28;
    }

}
void get_date_possibilities()
{
    days.push_back(32);
    for (int i = 0; i < years.size(); i++)
    {
        int control_years = ((years[i] / 1000) * 6 + ((years[i] / 100) % 10) * 5 + ((years[i] / 10) % 10) * 4 + (years[i] % 10) * 3);
        for (int j = 0; j < months.size(); j++)
        {
            int control_months = ((months[j] / 10) * 8 + (months[j] % 10) * 7);
            for (int k = 0; days[k] <= last_day_of_month(years[i], months[j]); k++)
            {
                control_date[
                    ((days[k] / 10) * 10 + (days[k] % 10) * 9 + control_months + control_years) % 19
                ] += 1;
            }
        }
    }
}


vector<ll> control_arbitrary(19, 0);
void get_arbitrary_possibilities()
{
    vector<int> multiplier {0, 2, 10, 9, 8, 7, 6, 5, 4, 3, 2};
    vector<vector<ll>> arbitrary(11, vector<ll>(19, 0));
    arbitrary[0][0] = 1;
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            if (pattern[i + 7] == 'X' || pattern[i + 7] - '0' == j)
            {
                for (int k = 0; k < 19; k++)
                {
                    arbitrary[i][(k + j * multiplier[i]) % 19] += arbitrary[i - 1][k];
                }
            }
        }
    }

    for (int i = 0; i < 19; i++)
    {
        control_arbitrary[i] = arbitrary[10][i];
    }
}
vector<ll> control(10, 0);
void get_combined_possibilities()
{
    for (int i = 0; i < 19; i++)
    {
        for (int j = 0; j < 19; j++)
        {
            if ((i + j) % 19 <= 9)
            {
                control[(i + j) % 19] += control_date[i] * control_arbitrary[j];
            }
            else
            {
                control[19 - (i + j) % 19] += control_date[i] * control_arbitrary[j];
            }
        }
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> pattern;

    get_days();
    get_months();
    get_years();
    get_date_possibilities();
    get_arbitrary_possibilities();
    get_combined_possibilities();
    
    if (pattern[18] == 'X')
    {
        ll sum = 0;
        for (int i = 0; i < 10; i++)
        {
            sum += control[i];
        }
        cout << sum;
    }
    else
    {
        cout << control[pattern[18] - '0'];
    }
}