#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <ctype.h>

#include "../utils.hpp"
//Im only using namespace std because leetcode does it
using namespace std;

//167 Two Sum 2 - Input Array Is Sorted
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target){
        for(int i = 0; i < numbers.size()-1; i++){
            int l = i + 1;
            int r = numbers.size()-1;
            while(l <= r){
                int m = l + (r-l)/2;
                if(numbers[m] + numbers[i] < target){
                    l = m + 1;
                }
                else if(numbers[m] + numbers[i] > target){
                    r = m -1;
                }
                else{
                    return {i+1, m+1};
                }
            }
        }
        return {};
    }
};

void test(){
    Solution solution;
    int maxWidth = 16;
    vector<int> numbers = {2,7,11,15};
    // vector<int> numbers = {1,2,4,7};
    int target =  9;
    vector<int> result = solution.twoSum(numbers, target);
    printVector(result);
    // cout << result << endl;
}