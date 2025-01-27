#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> largest_element_rec(vector<int> &arr)
    {
        int n = arr.size();
        int largest = arr[0];
        for (int i = 0; i < n; i++)
        {
            if (largest < arr[i])
            {
                largest = arr[i];
            }
        }
        return largest;
    }
};