#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> selection_sort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = n-1; i >= 0; i--)
    {
        int diditswap = 0;
        for(int j = 0; j <= i-1; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j+1], arr[j]);
                diditswap = 1;
            }
        }
        if(diditswap == 0){
            break;
        }
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