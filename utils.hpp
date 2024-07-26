#pragma once

//print an array of items
template <typename T>
void printVector(std::vector<T> v){
    for(T i : v){
        std::cout << i << " ";
    }
    std::cout << std::endl;
};

