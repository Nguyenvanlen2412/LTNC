#include <iostream>
using namespace std;

void in(int n){
    for (int i=n-1; i>=0; i--){
        for (int j=0;j<(2*n-1); j++){
            if(j<2*n-1-i && j>=i) cout << '*';
            else cout << ' ';
        }
        cout << endl;
    }
}
int main()
{
    int n;
    cin >> n;
    in(n);
    return 0;
}
