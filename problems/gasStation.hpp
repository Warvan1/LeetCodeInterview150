#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>

#include "../utils.hpp"
//Im only using namespace std because leetcode does it
using namespace std;

//12 - 134. Gas Station
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost){
        for(int o = 0; o < gas.size(); o++){
            int total = 0;
            int i = o;
            for(int j = 0; j < gas.size(); j++){
                total += gas[i] - cost[i];
                if(total < 0) break;
                i++;
                if(i >= gas.size()) i = 0;
            }
            if(total >= 0) return o;
        }
        return -1;
    }
};

void test(){
    Solution solution;
    // vector<int> gas = {1,2,3,4,5};
    // vector<int> cost = {3,4,5,1,2};
    // vector<int> gas = {1,3,3,3,5};
    // vector<int> cost = {3,4,5,1,2};
    vector<int> gas = {3,1,1};
    vector<int> cost = {1,2,2};
    int result = solution.canCompleteCircuit(gas, cost);
    cout << result << endl;
}