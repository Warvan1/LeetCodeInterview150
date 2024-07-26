#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "../utils.hpp"
//Im only using namespace std because leetcode does it
using namespace std;

//5 - 169. Majority Element
//my first solution using sorting
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        // printVector(nums);
        return nums[nums.size() / 2];
    }
};

//moore voting algorithm I did not make that I copy pasted after
class Solution2 {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = 0;
        
        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            
            if (num == candidate) {
                count++;
            } else {
                count--;
            }
        }
        
        return candidate;
    }
};

void test(){
    Solution solution;
    vector<int> nums = {2};
    std::cout << solution.majorityElement(nums) << std::endl;
}