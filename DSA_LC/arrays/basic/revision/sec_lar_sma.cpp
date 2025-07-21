#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int second_lar_sma(vector<int> &arr)
    {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        if (n == 0 || n == 1)
        {
            cout << "Array is empty or has only one element." << endl;
            return 0;
        }
        int second_smallest = arr[1];
        int second_largest = arr[n - 2];
        cout << "Second Smallest: " << second_smallest << endl;
        cout << "Second Largest: " << second_largest << endl;
        return 0;
    }
};