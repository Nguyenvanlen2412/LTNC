#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<n-1;i++){
        for (int j=0;j<n-i-1;j++){
            if (a[j]>a[j+1]) swap(a[j],a[j+1]);
        }
    }
    int tongchan=0, tongle=0;
    for (int i=0;i<n;i++){
        if (a[i]%2==0) tongchan+=a[i];
        else tongle+=a[i];
    }
    cout << a[0] << "\n" << a[n-1] << "\n" << tongchan << "\n" << tongle;
    return 0;
}
