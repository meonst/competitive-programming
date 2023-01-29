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
using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    int M;
    cin >> N >> M;
    string pokemon;
    vector<string> pokedex(N + 1);
    unordered_map<string, int> pokedex_name;
    for (int i = 1; i < N + 1; i++)
    {
        string pokemon;
        cin >> pokemon;
        pokedex[i] = pokemon;
        pokedex_name[pokemon] = i;
    }

    for (int i = 0; i < M; i++)
    {
        string arg;
        cin >> arg;
        if (pokedex_name.find(arg) == pokedex_name.end())
            printf("%s\n", pokedex[stoi(arg)].c_str());
        else
        {
            printf("%d\n", pokedex_name[arg]);
        }
    }
}
