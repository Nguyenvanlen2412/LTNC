#include <iostream>
using namespace std;
int main()
{
    int n, index=0;
    cin >> n;
    if (n<=1) cout << "no";
    else{
    for (int i=2;i<=n;i++){
        if (n%i==0) index++;
    }
    if (index==1) cout << "yes";
    else cout << "no";
    }
    return 0;
}
