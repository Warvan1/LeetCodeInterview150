#include <iostream>
#include <vector>
#include <string>
#include <climits>

#include "../utils.hpp"
//Im only using namespace std because leetcode does it
using namespace std;

//6 zigzag conversion

// solution explination
// example x = 5

// 0       8          16   i % 2(x-1) = 0 
// 1     7 9       15 17   i % 2(x-1) = 1 or 2(x-1) - 1 = 7
// 2   6   10    14   18   i % 2(x-1) = 2 or 2(x-1) - 2 = 6
// 3 5     11  13          i % 2(x-1) = 3 or 2(x-1) - 3 = 5
// 4       12              i % 2(x-1) = 4 = 2(x-1) - 4 = x-1

// O(x*n)
class Solution {
public:
    string convert(string s, int numRows){
        if(numRows == 1){
            return s;
        }
        string result = "";
        int w = (numRows-1) * 2; // 2(x-1)
        for(int row = 0; row < numRows; row++){
            for(int i = 0; i < s.length(); i++){
                if(i % w == row || i % w == w - row){
                    result += s[i];
                }
            }

            if(result.length() == s.length()) break;
        }

        return result;
    }
};

void test(){
    Solution solution;
    string s = "paypalishiring";
    int numRows = 3;
    string result = solution.convert(s, numRows);
    cout << result << endl;
}