#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "../utils.hpp"
//Im only using namespace std because leetcode does it
using namespace std;

//11 - 274. H-Index
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums){
        int product = 1;
        int zeros = 0;
        for(int num : nums){
            if(num == 0){
                zeros++;
                if(zeros == 2){
                    break;
                }
            }
            else{
                product *= num;
            }
        }
        vector<int> result(nums.size(), 0);
        if(zeros == 2){
            return result;
        }
        if(zeros == 1){
            for(int i = 0; i < nums.size(); i++){
                if(nums[i] == 0){
                    result[i] = product;
                }
            }
        }
        else{
            for(int i = 0; i < nums.size(); i++){
                result[i] = product / nums[i];
            }
        }
        return result;
    }
};

void test(){
    Solution solution;
    vector<int> nums = {1,2,3,4};
    vector<int> nums2 = {-1,1,0,-3,3};
    vector<int> nums3 = {1,0,3,0,2,4,0,5};
    
    printVector(solution.productExceptSelf(nums));
    printVector(solution.productExceptSelf(nums2));
    printVector(solution.productExceptSelf(nums3));
}