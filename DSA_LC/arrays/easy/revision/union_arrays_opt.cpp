#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> union_arrays(vector<int> &arr1, vector<int> &arr2)
{
    int n = arr1.size();
    int m = arr2.size();
    vector<int> result;
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (arr1[i] <= arr2[j])
        {
            if (result.size() == 0 || result.back() != arr1[i])
            {
                result.push_back(arr1[i]);
            }
            i++;
        }
        else
        {
            if (result.size() == 0 || result.back() != arr2[j])
            {
                result.push_back(arr2[j]);
            }
            j++;
        }
    }
    while (i < n)
    {
        if (result.size() == 0 || result.back() != arr1[i])
        {
            result.push_back(arr1[i]);
        }
        i++;
    }
    while (j < m)
    {
        if (result.size() == 0 || result.back() != arr2[j])
        {
            result.push_back(arr2[j]);
        }
        j++;
    }
    return result;
}