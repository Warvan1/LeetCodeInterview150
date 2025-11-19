#include <iostream>
#include <vector>
#include <string>

#include "../utils.hpp"
//Im only using namespace std because leetcode does it
using namespace std;

//12 - 134. Gas Station
//I was so confused trying to solve this problem that I had to look up the solution
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost){
        int sumGas = 0;
        int sumCost = 0;
        for(int i = 0; i < gas.size(); i++){
            sumGas += gas[i];
            sumCost += cost[i];
        }
        if(sumGas < sumCost){
            return -1;
        }

        int currentGas = 0;
        int start = 0;
        for(int i = 0; i < gas.size(); i++){
            currentGas += gas[i] - cost[i];
            if(currentGas < 0){
                currentGas = 0;
                start = i+1;
            }
        }
        return start;
    }
};

void test(){
    Solution solution;
    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};
    // vector<int> gas = {1,3,3,3,5};
    // vector<int> cost = {3,4,5,1,2};
    // vector<int> gas = {3,1,1};
    // vector<int> cost = {1,2,2};
    int result = solution.canCompleteCircuit(gas, cost);
    cout << result << endl;
}