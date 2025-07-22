#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotate_array(vector<int> &nums, int k)
{
    int n = nums.size();
    if (k > n)
    {
        k %= n;
    }
    reverse(nums.begin(), nums.end());
    reverse(nums.begin() + k, nums.end());
    reverse(nums.begin(), nums.begin() + k);
}