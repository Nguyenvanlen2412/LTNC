#include <iostream>
using namespace std;
int main()
{
    int n, index=0;
    cin >> n;
    for (int i=1;i<=n/2;i++)
    {
        if (i*i==n) {index++;
        break;}
    }
    if(index==1) cout << n << " la so chinh phuong";
    else cout << n << " khong la so chinh phuong";
    return 0;
}
