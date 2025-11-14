#include <std_aliases.hpp>

void quotientAndReminder (int a,int b){
    while (a>0) {
        auto qr=std::div(a,b);
        std::cout<<"q="<<qr.quot<<" r="<<qr.rem<<'\n';
        a/=b;
    }
}