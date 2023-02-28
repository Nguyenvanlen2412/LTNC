#include <iostream>
#include <cmath>
using namespace std ;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    double s=1.0*(a+b+c)/2;
    double area;
    area = sqrt(s*(s-a)*(s-b)*(s-c));
    cout << area;
    return 0;
}
