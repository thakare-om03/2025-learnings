#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;


vector<int> union_arrays(vector<int> &arr1, vector<int> &arr2){
    set<int> st;
    int n = arr1.size();
    int m = arr2.size();
    vector<int> result;
    for(int i =0; i < n; i++){
        st.insert(arr1[i]);
    }
    for (int i = 0; i < m; i++)
    {
        st.insert(arr2[i]);
    }
    for (auto i : st)
    {
        result.push_back(i);
    }
    return result;
}