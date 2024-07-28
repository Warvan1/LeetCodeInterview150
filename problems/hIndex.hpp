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
    int hIndex(vector<int>& citations) {
        //sort in desending order
        sort(citations.begin(), citations.end(), greater<int>());

        //edge cases
        if(citations[0] == 0){
            return 0;
        }
        if(citations.size() == 1){
            return 1;
        }
        if(citations[citations.size()-1] >= citations.size()){
            return citations.size();
        }

        int h = citations.size() / 2;
        int left = 0;
        int right = citations.size()-1;

        while(true){
            int h = (left + right) / 2;
            if(citations[h] == h+1 || (citations[h] > h+1 && citations[h+1] <= h+1)){
                // printVector(citations);
                return h+1;
            }
            if(citations[h] < h+1){
                right = h - 1;
            }
            else{
                left = h + 1;
            }
        }
    }
};

void test(){
    Solution solution;
    vector<int> nums = {3,0,6,1,5};
    vector<int> nums2 = {4,0,6,3,5};
    vector<int> nums3 = {0,8,1,1,1,1};
    vector<int> nums4 = {0,8,9,10,5,5};
    
    std::cout << solution.hIndex(nums4) << std::endl;
}