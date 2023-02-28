#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cin >> n;
    double a[n], tong=0;
    for (int i=0;i<n;i++){
        cin >> a[i];
        tong+=a[i];
    }
    double tb, phuongsai, tmp=0;
    tb=tong/n;
    for (int i=0;i<n;i++){
        tmp+=((a[i]-tb)*(a[i]-tb));
    }
    phuongsai=sqrt(tmp/(n-1));
    cout << tong << "\n" << phuongsai;
    return 0;
}
