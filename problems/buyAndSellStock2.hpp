#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "../utils.hpp"
//Im only using namespace std because leetcode does it
using namespace std;

//8 - 122. Best Time to Buy and Sell Stock II
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int localMin = 0;
        int localMax = 0;
        int profit = 0;
        bool inc = false;
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] > prices[i-1] && inc == false){
                localMin = prices[i-1];
                inc = true;
            }
            else if(prices[i] < prices[i-1] && inc == true){
                localMax = prices[i-1];
                inc = false;
                profit += (localMax - localMin);
            }
        }
        //case where local max is last element
        if(inc == true){
            localMax = prices[prices.size()-1];
            profit += (localMax - localMin);
        }
        return profit;
    }
};

void test(){
    Solution solution;
    vector<int> nums = {7,1,5,3,6,4};
    vector<int> nums2 = {7,6,4,3,1};
    vector<int> nums3 = {1,2,3,4,5};

    std::cout << solution.maxProfit(nums3) << std::endl;
}