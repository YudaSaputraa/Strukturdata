#include <iostream>
using namespace std;

int main(){
    int a, b=10, *p, *q;
    a = 25;
    p = &a;
    cout<<"Nilai a\t  = "<<a<<endl;
    cout<<"Nilai a+b = "<<*p + b<<endl;
    q = &b;
    cout<<"Nilai q\t  = " <<*q;
}