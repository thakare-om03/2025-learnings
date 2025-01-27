#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool if_sorted(vector<int> &arr)
    {
        int n = arr.size();
        if(n<=1)
        {
            return true;
        }
        for (int i = 0; i < n-1; i++)
        {
            if(arr[i] > arr[i+1])
            {
                return false;
            }
        }
        return true;
    }
};