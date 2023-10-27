#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    map<string, string> words;

    // a b k d e g h i l m n ng o p r s t u w y
    // a b c d e f g h i j k l m n o p q r s t u v w x y z
//  vector<char> conversion = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    vector<char> conversion = {'a', 'b', ' ', 'd', 'e', ' ', 'g', 'h', 'i', ' ', 'c', 'l', 'm', 'n', 'p', 'q', ' ', 'r', 's', 't', 'u', ' ', 'w', ' ', 'y', ' '};
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string minsik_word;
        string converted_word = "";
        
        cin >> minsik_word;
        for (int j = 0; j < minsik_word.size(); j++)
        {
            if (minsik_word[j] == 'n' && j != minsik_word.size() - 1 && minsik_word[j + 1] == 'g')
            {
                converted_word += 'o';
                j++;
            }
            else
            {
                converted_word += conversion[minsik_word[j] - 97];
            }
        }
        words[converted_word] = minsik_word;
    }

    for (auto [key, value]: words)
    {
        cout << value << "\n";
    }
}
