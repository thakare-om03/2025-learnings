#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:
    vector<int> largest_element(vector<int>& arr){
    int n = arr.size();
    sort(arr.begin(), arr.end());
    return {arr[n-1]};
}
};