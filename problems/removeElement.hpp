#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "../utils.hpp"
//Im only using namespace std because leetcode does it
using namespace std;

//2 - 27. Remove Element
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        auto nextElement = std::find(nums.begin(), nums.end(), val);
        while(nextElement != nums.end()){
            *nextElement = nums[nums.size()-1];
            nums.pop_back();
            nextElement = std::find(nextElement, nums.end(), val);
        }
        // printVector(nums);
        return nums.size();
    }
};

void test(){
    Solution solution;
    vector<int> nums = {0,1,2,2,3,0,4,2};
    solution.removeElement(nums, 2);
}