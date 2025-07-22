#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> rotate_array(vector<int>& arr)
    {
        int n = arr.size();
        vector<int> temp(n);
        temp[n-1]=arr[0];
        for (int i = 1; i < n; i++)
        {
            temp[i-1]=arr[i];
        }
        return temp;
    }
};