#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int search_insert_pos(vector<int> &nums, int target)
{
    int n = nums.size();
    int left = 0;
    int right = nums.size() - 1;
    int index = n;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (nums[mid] >= target)
        {
            index = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return index;
}