#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "../utils.hpp"
//Im only using namespace std because leetcode does it
using namespace std;

//7 - 121. Best Time to Buy and Sell Stock
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = 0;
        for(int i = 0; i < prices.size(); i++){
            minPrice = std::min(minPrice, prices[i]);
            maxProfit = std::max(maxProfit, prices[i]-minPrice);
        }
        return maxProfit;
    }
};

void test(){
    Solution solution;
    vector<int> nums = {7,1,6,3,6,4};
    vector<int> nums2 = {7,6,4,3,1};
    std::cout << solution.maxProfit(nums) << std::endl;
}