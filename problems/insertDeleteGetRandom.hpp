#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <random>

#include <ctime>

#include "../utils.hpp"
//Im only using namespace std because leetcode does it
using namespace std;

//12 - 380. Insert Delete GetRandom O(1)
class RandomizedSet {
private:
    unordered_map<int, int> valToIndex;
    vector<int> values;

public:
    RandomizedSet() {
        //initialize random seed
        srand(time(nullptr));
    }
    
    bool insert(int val) {
        if(valToIndex.find(val) != valToIndex.end()){
            return false;
        }
        values.push_back(val);
        valToIndex[val] = values.size()-1;
        // printVector(values);
        return true;
    }
    
    bool remove(int val) {
        auto it = valToIndex.find(val);
        if(it == valToIndex.end()){
            return false;
        }
        //replace the element we are removing with the last element
        values[it->second] = values.back();
        valToIndex[values.back()] = it->second;
        //remove the last element
        values.pop_back();
        valToIndex.erase(val);
        // printVector(values);
        return true;
    }
    
    int getRandom() {
        //get a random index
        int randomIndex = std::rand() % values.size();
        return values[randomIndex];
    }
};

void test(){
    RandomizedSet* randomizedSet = new RandomizedSet();
    randomizedSet->insert(0);
    randomizedSet->insert(1);
    randomizedSet->remove(0);
    randomizedSet->insert(2);
    randomizedSet->remove(1);
    randomizedSet->getRandom();
}