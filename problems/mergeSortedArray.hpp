#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "../utils.hpp"
//Im only using namespace std because leetcode does it
using namespace std;

//1 - 88. Merge Sorted Array
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        std::vector<int> output;
        int mi = 0;
        int ni = 0;
        while(mi < m || ni < n){
            if(mi == m){
                output.push_back(nums2[ni]);
                ni++;
            }
            else if(ni == n){
                output.push_back(nums1[mi]);
                mi++;
            }
            else if(nums1[mi] <= nums2[ni]){
                output.push_back(nums1[mi]);
                mi++;
            }
            else{
                output.push_back(nums2[ni]);
                ni++;
            }
        }
        nums1 = output;
        // printVector(nums1);
    }
};

void test(){
    Solution solution;
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    solution.merge(nums1, 3, nums2, 3);
}