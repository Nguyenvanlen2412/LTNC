#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i=2; i<=n;i++){
        int dem1=0, dem2=0, dem3=0;
        for (int j=1;j<=i/2;j++){
            if (i%j==0) dem1++;
            if(i%j==0) dem2+=j;
            if (j*j==i)dem3++;
        }
        if (dem1==1) cout << i << " la so nguyen to" << endl;
        if (dem2==i) cout << i << " la so hoan hao" << endl;
        if (dem3==1) cout << i << " la so chinh phuong" << endl;
    }
    return 0;
}
