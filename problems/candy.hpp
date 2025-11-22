#include <iostream>
#include <vector>
#include <string>
#include <climits>

#include "../utils.hpp"
//Im only using namespace std because leetcode does it
using namespace std;

//135 Candy
//Incomplete as i was struggling to solve it
class Solution {
public:
    int candy(vector<int>& ratings){
        //calculate absMaxPos
        int absMax = 0;
        int absMaxPos = 0;
        for(int i = 0; i < ratings.size(); i++){
            if(ratings[i] > absMax){
                absMax = ratings[i];
                absMaxPos = i;
            }
        }

        //calculate absMinPos
        int absMin = INT_MAX;
        int absMinPos = 0;
        for(int i = 0; i < ratings.size(); i++){
            if(ratings[i] < absMin){
                absMin = ratings[i];
                absMinPos = i;
            }
        }

        //right of absMinPos
        int totalCandies = 1;
        int candyLevel = 1;
        int childrenSinceMax = 0;
        for(int i = absMinPos + 1; i < ratings.size(); i++){
            if(ratings[i-1] < ratings[i]){
                if(childrenSinceMax > 0){

                }
                candyLevel++;
                totalCandies += candyLevel;
            }
            else if(ratings[i-1] == ratings[i]){

            }
            else if(ratings[i-1] > ratings[i]){
                childrenSinceMax++;
            }
        }

        return totalCandies;
    }
};

void test(){
    Solution solution;
    // vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    // vector<int> ratings = {1,3,0,2,0,4,2,1,2,2};
    vector<int> ratings = {6,8,10,9,8,7,8,9,9,9,9,9,9}; //
    int result = solution.candy(ratings);
    cout << result << endl;
}