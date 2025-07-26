#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int xor1 = 0;
        for (auto num: nums)
        {
            xor1 ^= num;
        }
        return xor1;
    }
};
