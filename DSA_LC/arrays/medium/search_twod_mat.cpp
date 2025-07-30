#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool search_twod_matrix(vector<vector<int>> &arr, int target, int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] == target){
                return true;
            }
        }
    }
    return false;
}