#include <std_aliases.hpp>

int nbOfDigits(int n) {
    int nbOfDigits=0;
    while (n>0) {
        n/=10;
        nbOfDigits++;
    }
    return nbOfDigits;

}

bool isArmstrong(int num) {
    int result=0;
    int x=num;
    int exp=nbOfDigits(num);
    while (num>0) {
        int digit=num%10;
        num/=10;
        int temp=std::pow(digit,exp);
        result+=temp;
    }
    return result==x;
}