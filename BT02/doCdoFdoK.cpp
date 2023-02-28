#include <iostream>
using namespace std;
int main()
{
    cout <<"Fahrenheit"<<"\t" << "Celsius" << "\t" << "\t" << "Absolute Value" << endl;
    int n;
    do{
        cin >> n;
        double c, f;
        c = 1.0*(n-32)*5/9;
        f = c-273.15;
        cout << "\t" << "\t" << c << "\t" << "\t" << f << endl;
    }while(true);
    return 0;
}
