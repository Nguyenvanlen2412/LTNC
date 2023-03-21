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
    cout << rand(n);
    return 0;
}
