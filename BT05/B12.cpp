#include <iostream>
using namespace std;

int tohop(int n, int k)
{
    int tich1=1, tich2=1, tich3=1;
    for (int i=1;i<=n;i++) tich1*=i;
    for (int i=1;i<=k;i++) tich2*=i;
    for (int i=1;i<=n-k;i++) tich3*=i;
    return tich1/(tich2*tich3);
}
int main()
{
    int n, k;
    cin >> n >> k;
    if(k<=n) cout << tohop(n ,k);
    return 0;
}
