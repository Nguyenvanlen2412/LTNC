#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n], b[n];
    for (int i=0;i<n;i++){
        cin >> a[i];
        cin >> b[i];
    }
    for (int j=0;j<n;j++){
        int dem=0;
        for (int i=a[j];i<=b[j];i++){
            int x=0, c[100], tong=0, tich=1, z=i;
            do{
                c[x]=z%10;
                z=z/10;
                x++;
            }while(z!=0);
            for (int y=x-1;y>=0;y--){
                tong+=(c[y]*tich);
                tich*=10;
            }
            if (tong==i) dem++;
        }
        cout << dem << endl;
    }
    return 0;
}
