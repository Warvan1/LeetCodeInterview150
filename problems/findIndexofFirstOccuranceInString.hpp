#include <iostream>
#include <vector>
#include <string>
#include <climits>

#include "../utils.hpp"
//Im only using namespace std because leetcode does it
using namespace std;

//28 Find the Index of the First Occurance in a String
class Solution {
public:
    int strStr(string haystack, string needle){
        if(needle.length() > haystack.length()) return -1;
        for(int i = 0; i < haystack.length() - needle.length() + 1; i++){
            if(haystack.substr(i, needle.length()) == needle){
                return i;
            }
        }
        return -1;
    }
};

void test(){
    Solution solution;
    string s = "sadbutsad2";
    string needle = "sad3";
    int result = solution.strStr(s, needle);
    cout << result << endl;
}