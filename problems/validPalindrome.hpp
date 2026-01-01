#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <ctype.h>

#include "../utils.hpp"
//Im only using namespace std because leetcode does it
using namespace std;

//125 valid Palindrome
class Solution {
public:
    bool isPalindrome(string s){
        int first = 0;
        int last = s.length() -1;

        while(first <= last){
            cout << first << " " << last << endl;
            char currentFirst = s.at(first);
            char currentLast = s.at(last);
            if(!isalpha(currentFirst) && !isdigit(currentFirst)){
                first++;
                continue;
            }
            if(!isalpha(currentLast) && !isdigit(currentLast)){
                last--;
                continue;
            }
            if(tolower(currentFirst) != tolower(currentLast)){
                return false;
            }
            first++;
            last--;
        }
        return true;
    }
};

void test(){
    Solution solution;
    int maxWidth = 16;
    string s = "A man, a plan, a canal: Panama";
    string s2 = "0P";
    bool result = solution.isPalindrome(s2);
    cout << result << endl;
}