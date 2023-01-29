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
using namespace std;

unordered_map<string, int> atoms;
int get_value(string a)
{
    return int(a[0]);
}
bool is_uppercase(string a)
{
    int value = get_value(a);
    return (65 <= value && value <= 90);
}
bool is_left_bracket(string a)
{
    int value = get_value(a);
    return (value == 40);
}
bool is_right_bracket(string a)
{
    int value = get_value(a);
    return (value == 41);
}
bool is_number(string a)
{
    int value = get_value(a);
    return (48 <= value && value <= 57);
}
bool is_empty_string(string a)
{
    return (a.size() == 0);
}
string get_substring(string a, int begin, int length)
{
    if (begin + length <= a.size()) return a.substr(begin, length);
    else return "";
}

int get_mass(string molecule)
{
    int mass = 0; 
    int partial_mass, length;
    if (is_empty_string(molecule)) return 0;
    string single;
    int begin = 0;
    while (true)
    {
        length = 1;  
        single = get_substring(molecule, begin, 1);
        
        if (is_empty_string(single)) break;

        if (is_uppercase(single))
        {
            while (true)
            {
                string next_char = get_substring(molecule, begin + length, 1);
                if (is_uppercase(next_char) || is_left_bracket(next_char) || is_number(next_char) || is_empty_string(next_char)) break;
                length += 1;
            }
            string atom = get_substring(molecule, begin, length);

            if (atoms.find(atom) == atoms.end()) return -1;

            begin += length;
            length = 0;
            
            while (true)
            {
                string next_char = get_substring(molecule, begin + length, 1);
                if (is_number(next_char))
                    length += 1;
                else
                    break;
            }

            if (length == 0)
                mass += atoms[atom];
            else
            {
                int number = stoi(get_substring(molecule, begin, length));
                mass += atoms[atom] * number;
                begin += length;
            }
        }
        
        else if (is_left_bracket(single))
        {
            int bracket = 1;
            while (bracket > 0)
            {
                string next_char = get_substring(molecule, begin + length, 1);
                if (is_left_bracket(next_char))
                {
                    bracket += 1;
                }
                else if (is_right_bracket(next_char))
                {
                    bracket -= 1;
                }
                length += 1;
            }
            partial_mass = get_mass(get_substring(molecule, begin + 1, length - 2));
            begin += length;
            length = 0;

            if (partial_mass == -1) return -1;
            
            while (true)
            {
                string next_char = get_substring(molecule, begin + length, 1);
                if (is_number(next_char))
                    length += 1;
                else
                    break;
            }

            if (length == 0)
                mass += partial_mass;
            else
            {
                int number = stoi(get_substring(molecule, begin, length));
                mass += partial_mass * number;
                begin += length;
            }
        }
        if (begin >= molecule.size()) break;
    }


    return mass;
}


int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string atom, molecule;
    int mass;

    while (true)
    {
        cin >> atom;
        if (atom == "END_OF_FIRST_PART") break;
        cin >> mass;
        atoms[atom] = mass;
    }
    
    while (true)
    {
        cin >> molecule;
        if (molecule == "0") break;
        mass = get_mass(molecule);
        if (mass > 0) cout << mass;
        else cout << "UNKNOWN";
        cout << "\n";
    }
}
