#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>

using namespace std;

class Solution
{
public:
    int firstUniqChar(string s)
    {
        unordered_map<char, int> mapped;
        for (auto a : s)
        {
            mapped[a]++;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (mapped[s[i]] == 1)
            {
                return i;
            }
        }
        return -1;
    }
};