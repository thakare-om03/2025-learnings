#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> selection_sort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        int minimum = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minimum])
            {
                minimum = j;
            }
        }
        swap(arr[minimum], arr[i]);
    }
    return arr;
}

int main()
{
    vector<int> arr = {9, 56, 43, 2, 5, 10, 11, 8, 21};
    selection_sort(arr);
    for (auto num : arr)
    {
        cout << " " << num << " ";
    }
    return 0;
}