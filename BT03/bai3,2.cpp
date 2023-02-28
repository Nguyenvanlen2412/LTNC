#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n], b[10]={};
    for (int i=0;i<n;i++){
        cin >> a[i];
        b[a[i]]++;
    }
    for (int i=0;i<n;i++){
        if (b[a[i]]==0) continue;
        cout << a[i] << "\t" << b[a[i]] <<endl;
        b[a[i]]=0;
    }
    return 0;
}
