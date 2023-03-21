#include <iostream>
#include <cmath>
using namespace std;

int rnd(double n)
{
    double x;
    x=ceil(n);
    return x;
}
int main()
{
    double n;
    cin >> n;
    cout << rnd(n);
    return 0;
}
