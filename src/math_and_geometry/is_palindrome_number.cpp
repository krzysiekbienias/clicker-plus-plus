
bool isPalindrome(int x){
    if (x<0) return false;
    //also when we have number ending with zeros cannot be palindrome for instance 120 but not 0
    if (x%10==0 && x!=0) return false;

    int rev =0;
    while (rev>x){
        rev=rev*10+x%10;
        x/=10;
    }
    return (x==rev|| x==rev/10);

}

/*1221
rev<-1
x<-122

rev=1*10+2=12
 x=1
*/