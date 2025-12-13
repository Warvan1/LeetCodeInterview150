#include <iostream>
#include <vector>
#include <string>
#include <climits>

#include "../utils.hpp"
//Im only using namespace std because leetcode does it
using namespace std;

//68 Text Justification
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth){
        vector<string> output;
        int wordSum = 0;
        int wordLengthSum = 0;
        int start = 0;
        int end = 0;
        for(int i = 0; i < words.size(); i++){
            wordSum++;
            wordLengthSum += words[i].length();
            if(wordLengthSum + wordSum -1 > maxWidth){
                end = i - 1;
                wordSum--;
                wordLengthSum -= words[i].length();
                // cout << wordSum << " " << wordLengthSum << " " << start << " " << end << endl;

                string s = "";
                if(wordSum == 1){
                    s += words[end];
                    for(int k = wordLengthSum; k < maxWidth; k++){
                        s+= " ";
                    }
                }
                else{
                    //calculate spacing
                    int space = (maxWidth - wordLengthSum) / (wordSum - 1);
                    int spaceRemainder = (maxWidth - wordLengthSum) % (wordSum - 1);
                    // cout << space << " " << spaceRemainder << endl;
                    //justify
                    for(int j = start; j < end; j++){
                        s += words[j];
                        for(int k = 0; k < space; k++){
                            s+= " ";
                        }
                        if(spaceRemainder > 0){
                            s+= " ";
                            spaceRemainder--;
                        }
                    }
                    s += words[end];
                }

                output.push_back(s);
                start = i;
                wordSum = 1;
                wordLengthSum = words[i].length();
            }
        }
        string s = "";
        wordLengthSum = 0;
        for(int i = start; i < words.size(); i++){
            s += words[i];
            wordLengthSum += words[i].length();
            if(i != words.size() -1){
                s+= " ";
                wordLengthSum++;
            }
        }
        for(int i = wordLengthSum; i < maxWidth; i++){
            s += " ";
        }
        output.push_back(s);
        return output;
    }
};

void test(){
    Solution solution;
    vector<string> words = {"This", "is", "an", "example", "of", "text", "justification"};
    // vector<string> words = {"What","must","be","acknowledgment","shall","be"};
    int maxWidth = 16;
    vector<string> result = solution.fullJustify(words, maxWidth);
    printVector(result);
}