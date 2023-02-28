#include <iostream>
using namespace std;
int main()
{
    int min_, max_, step_size;
    cin >> min_ >> max_ >> step_size;
    cout <<"Fahrenheit"<<"\t" << "Celsius" << "\t" << "\t" << "Absolute Value" << endl;
    for (int i=min_; i<=max_ ; i+=step_size){
        double c, f;
        c = 1.0*(i-32)*5/9;
        f = c-273.15;
        cout << i << "\t" << "\t" << c << "\t" << "\t" << f << endl;
    }
    return 0;
}

