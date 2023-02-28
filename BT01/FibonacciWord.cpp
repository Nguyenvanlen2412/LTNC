#include <iostream>
using namespace std;
int main()
{
    string f[11], s;
    f[0]="a";
    f[1]="b";
    for (int i=2; i<11;i++)
    {
        f[i]=f[0]+f[1];
        s=f[1];
        f[0]=s;
        f[1]=f[i];
    }
    cout << f[10];
    return 0;
}
