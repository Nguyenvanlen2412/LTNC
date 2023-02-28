#include <iostream>
using namespace std;
int main()
{
    double a, b, c;
    cin >> a >> b >> c;
    double chuvi = a+b+c;
    if (a>=chuvi/2 || b>=chuvi/2 || c>=chuvi/2) cout << "khong phai tam giac";
    else {
        cout << chuvi <<endl;
        if (a==b && b==c) cout << "deu";
        else if ((a==b && b!=c) || (b==c && c!=a) || (c==a && a!=b)) cout << "can";
        else if (a*a==b*b+c*c || a*a+b*b==c*c || a*a+c*c==b*b) cout << "vuong";
        else if (a*a>b*b+c*c || a*a+b*b<c*c || a*a+c*c<b*b) cout << "tu";
        else cout << "nhon";
    }
    return 0;
}
