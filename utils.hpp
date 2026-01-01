#pragma once

//print a vector of items
template <typename T>
void printVector(std::vector<T>& v){
    for(T i : v){
        std::cout << i << " ";
    }
    std::cout << std::endl;
};

//print a 2d vector of items
template <typename T>
void printVector2d(std::vector<std::vector<T>>& v){
    for(std::vector<T> i : v){
        printVector(i);
    }
}

//print a map of items
template <typename K, typename V, template<typename, typename> class M>
void printMap(M<K, V>& m){
    for(auto & [key, value]: m) {
        std::cout << key << ": " << value << std::endl;
    }
}