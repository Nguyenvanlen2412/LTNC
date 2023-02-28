#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n], b[n+1] = { };
    for (int i=0;i<n;i++){
        cin >> a[i];
        b[a[i]]++;
    }
    for (int i=0;i<n;i++)
    {
        if (b[a[i]] != 1) {
            cout << "yes";
            return 0;
        }
    }
    cout << "no";
    return 0;
}
