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

bool is_palindrome(string A)
{
    int length = A.length();
    for (int i = 0; i < length / 2; i++) 
    {
        if (A[i] != A[length - i - 1]) return false;
    }
    return true;
}