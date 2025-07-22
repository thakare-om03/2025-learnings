#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> rotate_array_optimal(vector<int>& arr)
    {
        int n = arr.size();
        int first_element = arr[0];
        for (int i = 0; i < n-1; i++)
        {
            arr[i]=arr[i+1];
        }
        arr[n-1]=first_element;
        return arr;
    }
};