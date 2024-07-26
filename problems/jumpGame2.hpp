#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "../utils.hpp"
//Im only using namespace std because leetcode does it
using namespace std;

//10 - 45. Jump Game II 
class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() <= 1){
            return 0;
        }

        for(int i = nums.size()-2; i >= 0; i--){
            if(nums[i] == 0){
                continue;
            }
            if(i + nums[i] >= nums.size()-1){
                nums[i] = 1;
                continue;
            }

            int jumps = 0;
            for(int j = 1; j <= nums[i]; j++){
                if(nums[i+j] == 0){
                    continue;
                }
                if(nums[i+j] < jumps || jumps == 0){
                    jumps = nums[i+j];
                }
            }

            if(jumps != 0){
                nums[i] = jumps + 1;
            }
            else{
                nums[i] = 0;
            }
        }

        // printVector(nums);
        return nums[0];
    }
};

void test(){
    Solution solution;
    vector<int> nums = {2,3,1,1,4};
    vector<int> nums2 = {3,1,2,0,1,4};
    vector<int> nums3 = {2,3,0,1,4};
    vector<int> nums4 = {1,5};
    vector<int> nums5 = {5,9,3,2,1,0,2,3,3,1,0,0};
    std::cout << solution.jump(nums5) << std::endl;
}