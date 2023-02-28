#include <iostream>
using namespace std;
int main()
{
    int x, y, z;
    cin >> x >> y >> z;
    bool b;
    if (x-y>0 && y-z>0) b=1;
    else if (x-y<0 && y-z<0) b=1;
    else b= 0;
    cout << b;
    return 0;
}
