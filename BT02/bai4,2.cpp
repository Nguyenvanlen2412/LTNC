#include <iostream>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    int tich = a*b;
    while (a*b!=0){
        if (a>b) a=a%b;
        else b=b%a;
    }
    cout << tich/(a+b);
    return 0;
}
