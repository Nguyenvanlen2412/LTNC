#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i=0;i<n;i++) cin >>a[i];
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            for (int k=0;k<n;k++){
                if ((a[i]+a[j]+a[k])==0) {
                    cout << a[i] << ' ' << a[j] << ' ' << a[k];
                    return 0;
                }
            }
        }
    }
    return 0;
}
