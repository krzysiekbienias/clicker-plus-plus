
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

static bool palindromeHelper(const std::string& str,int left,int right ){
    if (left>=right)
    //it is a case that handles with "" , "a", i gdy wskazniki sie mina
    return true;
    if (str[left]!=str[right]){
        return false;
    }
    return palindromeHelper(str, left+1, right-1);
}

bool isPalindromeRecursion(const std::string& str){
    int n=str.size();
    return palindromeHelper(str, 0, n-1);
}

bool isPalindromeSentence(std::string str) {
    int left=0;
    int right=str.size()-1;
    while (left<=right){
        while (left<right &&!std::isalnum(static_cast<unsigned char>(str[left]))) ++left;
        while (left<right &&!std::isalnum(static_cast<unsigned char>(str[right]))) --right;

        //prevent from UB
        unsigned char a=static_cast<unsigned char>(str[left]);
        unsigned char b=static_cast<unsigned char>(str[right]);
        if(std::tolower(a)!=std::tolower(b)){
            return false;
        }
        left++;
        right--;
    }
    return true;
}