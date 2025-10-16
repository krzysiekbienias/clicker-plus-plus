#include "std_aliases.hpp"

using namespace stl;


void shuffleArr(vector<int>& arr) {
     if (arr.empty()) return ;
     size_t n= arr.size()-1;
     static thread_local std::mt19937 rng(std::random_device{}()); //one generator, seed fixed once
     std::uniform_int_distribution<size_t> dist(0,n);
     size_t i=dist(rng);
     while (n>0) {
          std::swap(arr[n],arr[i]);
          n--;
     }
}
