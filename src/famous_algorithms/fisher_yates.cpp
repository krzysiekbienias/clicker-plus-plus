#include "std_aliases.hpp"

using namespace stl;


void shuffleArr(vector<int>& arr) {
     if (arr.empty()) return ;
     size_t n= arr.size()-1;
     static thread_local std::mt19937 rng(std::random_device{}()); //one generator, seed fixed once
     for (size_t i = n - 1; i > 0; --i) {
          std::uniform_int_distribution<size_t> dist(0, i);
          size_t j = dist(rng);
          std::swap(arr[i], arr[j]);
     }
}
