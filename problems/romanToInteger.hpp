#include <iostream>
#include <vector>
#include <string>
#include <climits>

#include "../utils.hpp"
//Im only using namespace std because leetcode does it
using namespace std;

//13 Roman to Integer
class Solution {
public:
    int romanToInt(string s){
        int total = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'I'){
                if(s[i + 1] == 'V' && i < s.size() - 1){
                    total += 4;
                    i++;
                }
                else if(s[i + 1] == 'X' && i < s.size() - 1){
                    total += 9;
                    i++;
                }
                else{
                    total++;
                }
            }
            else if(s[i] == 'V'){
                total += 5;
            }
            else if(s[i] == 'X'){
                if(s[i + 1] == 'L' && i < s.size() - 1){
                    total += 40;
                    i++;
                }
                else if(s[i + 1] == 'C' && i < s.size() - 1){
                    total += 90;
                    i++;
                }
                else{
                    total += 10;
                }
            }
            else if(s[i] == 'L'){
                total += 50;
            }
            else if(s[i] == 'C'){
                if(s[i + 1] == 'D' && i < s.size() - 1){
                    total += 400;
                    i++;
                }
                else if(s[i + 1] == 'M' && i < s.size() - 1){
                    total += 900;
                    i++;
                }
                else{
                    total += 100;
                }
            }
            else if(s[i] == 'D'){
                total += 500;
            }
            else if(s[i] == 'M'){
                total += 1000;
            }
        }
        return total;
    }
};

void test(){
    Solution solution;
    // string s = "LVIII";
    string s = "MCMXCIV";
    int result = solution.romanToInt(s);
    cout << result << endl;
}