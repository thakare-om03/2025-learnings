#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int find_missing_num(vector<int> &arr){
    int n = arr.size();
    int expected_sum = n *(n+1)/2;
    int actual_sum = 0;
    for(int i = 0; i < n-1; i++){
        actual_sum += arr[i];
    }
    return expected_sum-actual_sum;
}