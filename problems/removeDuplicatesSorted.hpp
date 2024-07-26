#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "../utils.hpp"
//Im only using namespace std because leetcode does it
using namespace std;

//3 - 26. Remove Duplicates from Sorted Array
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        
        int pos = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nums[i-1]){
                nums[pos] = nums[i];
                pos++;
            }
        }

        // printVector(nums);
        return pos;
    }
};

void test(){
    Solution solution;
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    std::cout << solution.removeDuplicates(nums) << std::endl;
}