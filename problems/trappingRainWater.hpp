#include <iostream>
#include <vector>
#include <string>

#include "../utils.hpp"
//Im only using namespace std because leetcode does it
using namespace std;

//42 Trapping Rain Water
class Solution {
public:
    int trap(vector<int>& height){
        //calculate absMaxPos
        int absMax = 0;
        int absMaxPos = 0;
        for(int i = 0; i < height.size(); i++){
            if(height[i] > absMax){
                absMax = height[i];
                absMaxPos = i;
            }
        }

        int rainCollected = 0;
        //left of absMaxPos
        int prevMax = height[0];
        for(int i = 1; i < absMaxPos; i++){
            if(height[i] >= prevMax){
                prevMax = height[i];
            }
            else{
                rainCollected += prevMax - height[i];
                // cout << rainCollected << endl;
            }
        }

        //right of absMaxPos
        prevMax = height[height.size()-1];
        for(int i = height.size()-2; i > absMaxPos; i--){
            if(height[i] >= prevMax){
                prevMax = height[i];
            }
            else{
                rainCollected += prevMax - height[i];
                // cout << rainCollected << endl;
            }
        }

        return rainCollected;
    }
};

void test(){
    Solution solution;
    // vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> height = {1,3,0,2,0,4,2,1,2,2};
    int result = solution.trap(height);
    cout << result << endl;
}