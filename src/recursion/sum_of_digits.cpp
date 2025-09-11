

// Implement your sum_of_digits logic here.
int sumOfDigits(int n){
    if (n<=9) return n;
    else{
        return n%10+sumOfDigits(n/10);
    }
}

int sumOfDigitsIter(int n) {
    int sum=0;
    while (n>0) {
        sum+=n%10;
        n=n/10;
    }
    return sum;
}