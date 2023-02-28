#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[100], i=0, tong=0;
    do{
        a[i]=n%10;
        n=n/10;
        tong+=a[i];
        i++;
    }while (n!=0);
    cout << tong;
    return 0;
}
