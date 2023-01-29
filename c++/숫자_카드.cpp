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

using namespace std;





int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long N;
    long M;
    cin >> N;
    vector<long> cards(20000001, 0);

    for (int i = 0; i < N; i++) 
    {
        long card;
        cin >> card;
        cards[card + 10000000] = 1;
    }
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        long c;
        cin >> c;
        printf("%d ", cards[c + 10000000]);
    }
}
