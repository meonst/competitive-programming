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
    int group = 1;
    while (true)
    {
        cin >> N;
        if (N == 0) break;
        vector<string> kids(N, "");
        vector<vector<string>> message(N, vector<string>(N - 1, ""));
        bool were_they_nasty = false;
        for (int i = 0; i < N; i++)
        {
            cin >> kids[i];
            for (int j = 0; j < N - 1; j++)
            {
                cin >> message[i][j];
            }
        }
        cout << "Group " << group << "\n";
        group += 1;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N - 1; j++)
            {
                if (message[i][j] == "N")
                {
                    were_they_nasty = true;
                    string criminal = kids[(N + i - j - 1) % N];
                    cout << criminal << " was nasty about " << kids[i] << "\n";
                }
            }
        }
        if (!were_they_nasty) cout << "Nobody was nasty\n";
        cout << "\n";
    }

}
