
#include <string>

// Implement your palindrome_check logic here.
bool isPalindrome(std::string str) {
    int left=0;
    int right=str.size()-1;
    while (left<=right){
        if(str[left]!=str[right]){
            return false;
        }
        left++;
        right--;

    }
    return true;
}