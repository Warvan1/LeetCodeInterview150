#include <iostream>
#include <vector>
#include <string>
#include <climits>

#include "../utils.hpp"
//Im only using namespace std because leetcode does it
using namespace std;

//14 Longest Common Prefix
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs){
        int prefixLength = INT_MAX;
        for(int i = 1; i < strs.size(); i++){
            for(int j = 0; j < strs[0].size() && j < prefixLength; j++){
                if(j >= strs[i].size()){
                    prefixLength = j;
                    break;
                }
                else if(strs[0][j] != strs[i][j]){
                    prefixLength = j;
                    break;
                }
            }
            if(prefixLength == 0){
                return "";
            }
        }
        if(prefixLength == INT_MAX){
            return strs[0];
        }
        return strs[0].substr(0, prefixLength);
    }
};

void test(){
    Solution solution;
    vector<string> strs = {"flower", "flow", "flight"};
    // vector<string> strs = {"aaa", "aa", "aaa"};
    // vector<string> strs = {"aac","acab","aa","abba","aa"};
    string result = solution.longestCommonPrefix(strs);
    cout << result << endl;
}