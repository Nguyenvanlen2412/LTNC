#include <iostream>
using namespace std;

int rnd(double n)
{
    double i=0;
    while(i<n){
        i++;
    }
    if((n-i) == 0) return n;
    else{
        double x=0-(n-i);
        return n+x;
    }
}

int main()
{
    double n;
    cin >> n;
    cout << rnd(n);
    return 0;
}
