#include <iostream>
#include <ctime>
using namespace std;



int rand(int n)
{
	srand(time(NULL));
	return rand() % (n + 1);
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i=0;i<n;i++) a[i]=rand(50);
    for (int i=0;i<n;i++){
        for (int j=i;j<n;j++){
            for (int k=i;k<n;k++){
                if((a[i]+a[j]+a[k])%25==0) cout << a[i] << ' ' << a[j] << ' ' << a[k] << endl;
            }
        }
    }
    return 0;
}

