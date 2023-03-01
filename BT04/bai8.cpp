#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    double a[n], b[n];
    for (int i=0;i<n;i++) cin >> a[i] >> b[i];
    for (int i=0;i<n-1;i++){
        for (int j=i;j<n-2;j++){
            if (a[j]>a[j+1]) swap(a[j],a[j+1]);
        }
    }
    for (int i=0;i<n-1;i++){
        for (int j=i;j<n-2;j++){
            if (b[j]>b[j+1]) swap(b[j],b[j+1]);
        }
    }
    int index=0;
    for (int i=0;i<n;i++){
        if (b[i]-a[i]>=0) index++;
    }
    if (index==0) cout << "Yes";
    else cout << "no";
    return 0;
}
