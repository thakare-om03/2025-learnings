#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find_floor(vector<int> &nums, int target) //largest no in an array <= x
{
    int n = nums.size();
    int left = 0;
    int right = n - 1;
    int floor = -1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (nums[mid] <= mid)
        {
            floor = nums[mid];
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return floor;
}

int find_ceil(vector<int>&nums, int target){ // smallest no in an array >= x
    auto it = lower_bound(nums.begin(), nums.end(), target);
    return (it != nums.end()) ? *it : -1;
}