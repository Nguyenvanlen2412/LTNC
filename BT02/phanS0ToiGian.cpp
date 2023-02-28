#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int a, b;
    cin >> a >> b;
    int x=a, y=b;
    a=abs(a);
    b=abs(b);
    while (a*b!=0){
        if (a>b) a=a%b;
        else b=b%a;
    }
    cout << x/(a+b) << '/' << y/(a+b);
    return 0;
}
