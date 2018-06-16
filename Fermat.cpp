#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <NTL/ZZ.h>
using namespace NTL;
using namespace std;
ZZ expomod(ZZ a, ZZ b, ZZ m){
    ZZ exp;
    exp=1;
    ZZ x=ZZ(a%m);
    while(b>ZZ(0) && x>ZZ(1)){
        if(ZZ(b&1)!=ZZ(0)){
            exp=ZZ((exp*x)%m);
        }
        x=ZZ((x*x)%m);
        b=b>>1;
    }
    return exp;
}
bool fermat1(ZZ n, ZZ t){
    if(n==ZZ(3))
        return true;
    for(ZZ i(1);i<t;i++){
        srand(time(0));
        ZZ a;
        a=RandomBits_ZZ(8)%n-2;
        while(a<ZZ(2)){
            a=RandomBits_ZZ(8)%n-2;
        }
        ZZ r=expomod(a,ZZ(n-1),n);
        if(r!=ZZ(1)){
            return false;
        }
    }
    return true;
}
int main(){
    ZZ y;
    y=RandomBits_ZZ(1028);
    cout<<fermat1(y,ZZ(21));
}
