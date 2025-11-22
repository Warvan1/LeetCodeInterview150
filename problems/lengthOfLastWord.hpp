#include <iostream>
#include <vector>
#include <string>
#include <climits>

#include "../utils.hpp"
//Im only using namespace std because leetcode does it
using namespace std;

//58 length of last word
class Solution {
public:
    int lengthOfLastWord(string s){
        bool inWord = false;
        int count = 0;
        for(int i = s.size()-1; i >= 0; i--){
            if(s[i] != ' '){
                count++;
                inWord = true;
            }
            else if(inWord){
                break;
            }
        }
        return count;
    }
};

void test(){
    Solution solution;
    string s = "   fly me   to   the moon  ";
    int result = solution.lengthOfLastWord(s);
    cout << result << endl;
}