#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void reverse_arr(vector<int> &arr, int start, int end){
    while (start <= end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

vector<int> rotate_array(vector<int> &arr, int k){
    int n = arr.size();
    k %= n;
    reverse_arr(arr, 0, k-1);
    reverse_arr(arr, k, n-1);
    reverse_arr(arr, 0, n-1);
}