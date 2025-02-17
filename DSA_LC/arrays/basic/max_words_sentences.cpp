#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
    public:

    int max_words(vector<string>& sentences){
        int maximum = 0;
        for(auto i : sentences){
            int count = 1;
            for(auto character : i){
                if(character == ' '){
                    count++;
                }
            }
            maximum = max(maximum, count);
        }
        return maximum;
    }
};