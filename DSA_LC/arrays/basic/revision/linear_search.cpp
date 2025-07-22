#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool linear_search(vector<int>& arr, int target)
    {
        int n = arr.size();
        for(int i = 0; i < n ;i++){
            if(arr[i]==target){
                return i;
            }
        }
        return -1;
    }
};