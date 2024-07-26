#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "../utils.hpp"
//Im only using namespace std because leetcode does it
using namespace std;

//9 - 55. Jump Game
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int end = nums.size()-1;
        for(int i = end; i >= 0; i--){
            if(i + nums[i] >= end){
                end = i;
            }
            std::cout << end << std::endl;
        }
        if(end == 0){
            return true;
        }
        return false;
    }
};

void test(){
    Solution solution;
    vector<int> nums = {2,3,1,1,4};
    vector<int> nums2 = {3,2,1,0,1,4};
    std::cout << solution.canJump(nums2) << std::endl;
}