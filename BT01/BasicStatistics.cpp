#include <iostream>
using namespace std;
int main()
{
    int n, x, y;
    cin >> n;
    int a[n], tong;
    double mean;
    for (int i=0;i<n;i++){
            cin >> a[i];
            tong+=a[i];}
    mean=1.0*tong/n;
    x=a[0];
    y=a[0];
    for (int i=0;i<n;i++){
        if(x<=a[i]) x=a[i];
        if(y>=a[i]) y=a[i];
    }
    cout << "mean: " << mean <<"\n"<<"max: " << x << "\n" << "min: " << y;
    return 0;
}
