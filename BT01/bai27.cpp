#include <iostream>
using namespace std;
int main()
{
    int n;
    while(cin >> n){
        if (n==-1){
            cout << "Bye";
            break;
        }
        if(n>=0 && n%5==0) cout << n/5;
        else cout << -1;
    }
    return 0;
}
