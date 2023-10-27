#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string all, explosion;
    cin >> all >> explosion;
    
    vector<string> chars;
    string temp = "";
    int index = 0;
    for (int i = 0; i < all.size(); i++)
    {
        if (explosion[index] == all[i])
        {
            if (index == 0)
            {
                index += 1;
                
                if (index == explosion.size())
                {
                    if (temp != "") chars.push_back(temp);
                    index = 0;
                    temp = "";
                }
                else
                {
                    if (temp != "") chars.push_back(temp);
                    temp = "";
                    temp += all[i];
                }
            }
            else
            {
                index += 1;
                if (index == explosion.size())
                {
                    index = 0;
                    temp = "";
                    if (chars.size() > 0)
                    {
                        temp = chars[chars.size() - 1];
                        if (explosion.find(temp) == 0)
                        {
                            index = temp.size();
                            chars.pop_back();
                        }
                        else
                        {
                            temp = "";
                        }
                    }

                }
                else
                {
                    temp += all[i];
                }
            }
        }
        else
        {
            if (index == 0)
            {
                temp += all[i];
            }
            else
            {
                if (temp != "") chars.push_back(temp);
                index = 0;
                temp = "";
                i--;
            }
        }
    }
    chars.push_back(temp);

    string result = "";
    for (int i = 0; i < chars.size(); i++)
    {
        result.append(chars[i]);
        // cout << i << ", " << chars[i] << "\n";
    }
    cout << (result == "" ? "FRULA" : result);

}
