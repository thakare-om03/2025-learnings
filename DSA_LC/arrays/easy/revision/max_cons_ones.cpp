#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int count_max_cons_ones(vector<int> &arr)
{
    int n = arr.size();
    int count = 0;
    int max_count = 0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i]==1){
            count++;
        }
        else{
            count = 0;
        }
        max_count = max(count, max_count);
    }
    return max_count;
}