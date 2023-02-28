#include <iostream>
using namespace std;
int main()
{
    double x;
    int y;
    double luyThua = 1;
    cin >> x >> y;
    if (y==0) luyThua = 1;
    else if (y > 0){
        for (int i=0; i<y; i++)
            luyThua*=x;
    }
    else{
        for (int i=0; i>y; i--)
            luyThua*=(1/x);
    }
    cout << luyThua;
    return 0;
}
