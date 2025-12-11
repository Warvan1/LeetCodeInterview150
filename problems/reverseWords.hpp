#include <iostream>
#include <vector>
#include <string>
#include <climits>

#include "../utils.hpp"
//Im only using namespace std because leetcode does it
using namespace std;

//151 reverse words in string
class Solution {
public:
    string reverseWords(string s){
        string result = "";
        int state = 0; //0: not in word 1: in word
        int end = 0;
        int start = 0;
        for(int i = s.length()-1; i >= 0; i--){
            if(state == 0){
                if(s[i] != ' '){
                    state = 1;
                    end = i;
                }
            }
            if(state == 1){
                if(s[i] == ' '){
                    state = 0;
                    start = i+1;
                    result += s.substr(start, end-start + 1) += " ";
                }
                else if(i == 0){
                    start = i;
                    result += s.substr(start, end-start + 1) += " ";
                }
            }
        }
        result.pop_back();
        return result;
    }
};

void test(){
    Solution solution;
    string s = " fly me   to   the moon  ";
    string result = solution.reverseWords(s);
    cout << result << endl;
}