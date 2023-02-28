#include <iostream>
using namespace std;
int main()
{
    int n, a;
    while (cin >> n){
       if (n==a) continue;
       a=n;
       cout << a << ' ';
       if (n<0) break;
    }
    return 0;
}
