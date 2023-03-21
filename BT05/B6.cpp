#include <iostream>
using namespace std;

int GCD(int n, int m)
{
    while(n*m != 0){
        if(n>=m) n=n%m;
        else m=m%n;
    }
    return n+m;

}
int main()
{
    int a, b;
    cin >> a >> b;
    if (GCD(a, b)==1) cout << "true";
    else cout << "false";
    return 0;
}
