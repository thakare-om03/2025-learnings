#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> inter_arr(vector<int> &arr1, vector<int> &arr2)
{
    int n = arr1.size();
    int m = arr2.size();
    vector<int> result;
    int temp[m] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr1[i] == arr2[j] && temp[j] == 0)
            {
                result.push_back(arr1[i]);
                temp[j] = 1;
                break;
            }
            if (arr2[j] > arr1[i])
                break;
        }
    }
    return result;
}