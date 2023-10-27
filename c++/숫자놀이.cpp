#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int M, N;

    map<string, int> numbers;
    vector<string> conversion = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    cin >> M >> N;
    for (int i = M; i <= N; i++)
    {
        string converted;
        if (i < 10)
        {
            converted = conversion[i];
        }
        else
        {
            converted = conversion[i / 10] + " " + conversion[i % 10];
        }
        // cout << converted << "\n";
        numbers[converted] = i;
    }
    int j = 0;
    for (auto i = numbers.begin() ; i !=  numbers.end(); i++)
	{
        j++;
		cout << i -> second << " ";
        if (j == 10)
        {
            cout << "\n";
            j = 0;
        }
	}
}
