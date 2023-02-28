#include <iostream>
using namespace std;
int main()
{
    double a1, b1, c1, a2, b2, c2;
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
    double dx, dy, d;
    dx=c1*b2-c2*b1;
    dy=a1*c2-a2*c1;
    d=a1*b2-a2*b1;
    if (d==0 && dx==0 && dy==0) cout << "phuong trinh co vo so nghiem";
    else if (d==0 && (dx!=dy || dx!=0 || dy!=0)) cout << "phuong trinh vo nghiem";
    else cout << "x = " << dx/d << "\n" << "y = " << dy/d;
    return 0;
}
