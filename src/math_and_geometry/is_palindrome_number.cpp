
bool isPalindrome(int x){
    if (x<0) return false;
    if (x%10==0 && x!=0) return false;
    int hr=0; //hr = half reverse
    while(hr<x){
        hr=hr*10+x%10;
        x/=10;
    }
    return (x==hr || x==hr/10);

}

/*1221
rev<-1
x<-122

rev=1*10+2=12
 x=1
*/