
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


int count1 = 0;
int count2 = 0;
int fib(int n)
{
    if (n == 1 || n == 2) 
    {
        count1 += 1;
        return 1;
    }
    else return (fib(n - 1) + fib(n - 2));
}

int fibonacci(int n)
{
    
    vector<int> f(41, 1);
    f[1] = 1;
    f[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        count2 += 1;
        f[i] = f[i - 1] + f[i - 2];
    }
    return f[n];
}



int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    fib(N);
    fibonacci(N);
    printf("%d %d", count1, count2);
}
