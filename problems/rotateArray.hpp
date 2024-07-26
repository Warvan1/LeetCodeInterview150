#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "../utils.hpp"
//Im only using namespace std because leetcode does it
using namespace std;

//6 - 189. Rotate Array
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        std::vector<int> t;
        for(int i = k; i > 0; i--){
            t.push_back(nums[nums.size()-i]);
        }
        for(int i = nums.size()-1; i >= k; i--){
            nums[i] = nums[i-k];
        }
        for(int i = 0; i < k; i++){
            nums[i] = t[i];
        }

        // printVector(nums);
    }
};

void test(){
    Solution solution;
    vector<int> nums = {99,-1,-100,3};
    solution.rotate(nums, 5);
}