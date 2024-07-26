#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "../utils.hpp"
//Im only using namespace std because leetcode does it
using namespace std;

//4 - 80. Remove Duplicates from Sorted Array II
//my solution i made
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 1){
            return nums.size();
        }
        
        int pos = 1;
        if(nums[0] == nums[1]){
            pos++;
        }

        for(int i = pos; i < nums.size()-1; i++){
            if(nums[i] > nums[i-1]){
                nums[pos] = nums[i];
                pos++;
                if(nums[i] == nums[i+1]){
                    nums[pos] = nums[i];
                    pos++;
                }
            }
        }

        if(nums[nums.size()-2] != nums[nums.size()-1]){
            nums[pos] = nums[nums.size()-1];
            pos++;
        }

        // printVector(nums);
        return pos;
    }
};

//"better" solution i copy pasted and then changed a bit
class Solution2 {
public:
    int removeDuplicates(vector<int>& nums) {
        int i =2;
        // int ele= nums[0];
        for(auto ele : nums)
        {
            if(nums[i-2] != ele)
            {
                nums[i] = ele;
                i++;
            }
        }
    // printVector(nums);
    return i ;
    }
};

void test(){
    Solution solution;
    vector<int> nums = {0,0,1,1,1,1,2,3,3};
    std::cout << solution.removeDuplicates(nums) << std::endl;
}