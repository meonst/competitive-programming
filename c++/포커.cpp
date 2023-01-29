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


void print_with_format(int a, int b)
{
    cout << a/gcd(a, b) << "/" << b/gcd(a,b) << "\n";
}

int main()
{

    int all_possibilities = 20358520;

    int top = 6612900;
    int one_pair = 9730740;
    int two_pair = 2532816;

    int triple = 732160;
    int straight = 282060;
    int back_straight = 39780;

    int mountain = 39780;
    int flush = 205976;
    int full_house = 165984;

    int four_card = 14664;
    int straight_flush = 1472;
    int royal_straight_flush = 188;




    print_with_format(top, all_possibilities);
    print_with_format(one_pair, all_possibilities);
    print_with_format(two_pair, all_possibilities);

    print_with_format(triple, all_possibilities);
    print_with_format(straight, all_possibilities);
    print_with_format(back_straight, all_possibilities);

    print_with_format(mountain, all_possibilities);
    print_with_format(flush, all_possibilities);
    print_with_format(full_house, all_possibilities);

    print_with_format(four_card, all_possibilities);
    print_with_format(straight_flush, all_possibilities);
    print_with_format(royal_straight_flush, all_possibilities);
    
}
