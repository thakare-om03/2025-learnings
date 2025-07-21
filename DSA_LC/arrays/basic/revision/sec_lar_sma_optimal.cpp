#include <iostream>
#include <vector>
#include <algorithm>
#include<climits>
using namespace std;

int secondlargest(vector<int> &arr, int n){
    int largest = arr[0];
    int second_largest = -1;
    for(int i = 1; i < n; i++){
        if(arr[i] > largest){
            second_largest = largest;
            largest = arr[i];
        }
        else if(arr[i] < largest && arr[i] > second_largest){
            second_largest = arr[i];
        }
    }
    return second_largest;
}
int secondsmallest(vector<int> &arr, int n)
{
    int smallest = arr[0];
    int second_smallest = INT_MAX;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < smallest)
        {
            second_smallest = smallest;
            smallest = arr[i];
        }
        else if (arr[i] != smallest && arr[i] < second_smallest)
        {
            second_smallest = arr[i];
        }
    }
    return second_smallest;
}

int find_sec_lar_sma(vector<int> &arr, int n){
    cout << secondlargest(arr,n) << endl;
    cout << secondsmallest(arr,n) << endl;
}