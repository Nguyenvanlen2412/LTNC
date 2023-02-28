#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n][n];
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            a[i][j]=j+1+i;
            if (a[i][j]>10) a[i][j]=a[i][j]-10;
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cout << a[i][j] << ' ';}
            cout << endl;
    }
    return 0;
}
