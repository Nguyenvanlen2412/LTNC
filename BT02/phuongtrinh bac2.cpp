#include <iostream>
#include <cmath>

using namespace std;
int main()
{
    double a, b, c;
    cin >> a >> b >> c;
    if (a==0){
        if (b==0 && c!=0) cout << "phuong trinh vo nghiem";
        if (b==0 && c==0) cout << "phuong trinh co co so nghiem";
        if (b!=0) cout << "x = " << -c/b;
    }
    else {
        double delta=b*b-4*a*c;
        if (delta < 0) cout << "phuong trinh vo nghiem";
        if (delta == 0) cout << "x = " << -b/(2*a);
        if (delta > 0) {
                double x1 =  (-b-sqrt(delta))/(2*a);
                double x2 = (-b+sqrt(delta))/(2*a);
                cout << "x1 = " << x1 << "\n" << "x2 = " << x2;
    }
    }
    return 0;
}
