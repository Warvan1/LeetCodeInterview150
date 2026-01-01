#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <ctype.h>

#include "../utils.hpp"
//Im only using namespace std because leetcode does it
using namespace std;

//392 is subsequence
class Solution {
public:
    bool isSubsequence(string s, string t){
        if(s.length() == 0){
            return true;
        }
        int k = 0;
        for(int i = 0; i < t.length(); i++){
            if(t[i] == s[k]){
                k++;
            }
            if(k == s.length()){
                return true;
            }
        }
        return false;
    }
};

void test(){
    Solution solution;
    int maxWidth = 16;
    string s = "abc";
    string t = "ahbgdc";
    bool result = solution.isSubsequence(s, t);
    cout << result << endl;
}