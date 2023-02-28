#include <iostream>
using namespace std;

string one[] = { "", "one ", "two ", "three ", "four ",
                 "five ", "six ", "seven ", "eight ",
                 "nine ", "ten ", "eleven ", "twelve ",
                 "thirteen ", "fourteen ", "fifteen ",
                 "sixteen ", "seventeen ", "eighteen ",
                 "nineteen " };

string ten[] = { "", "", "twenty ", "thirty ", "forty ",
                 "fifty ", "sixty ", "seventy ", "eighty ",
                 "ninety " };

string numToWords(int n, string s)
{
    string str = "";
    if (n>=100)
        str += one[n/100] + "hundred " + ten[(n%100)/10] + one[n%10];

    if (n > 19 && n<100)
        str += ten[n / 10] + one[n % 10];
    else
        str += one[n];

    if (n)
        str += s;

    return str;
}


string convertToWords(long n)
{
    string out;

    out += numToWords(((n / 1000000) % 1000), "million ");


    out += numToWords(((n / 1000) % 1000), "thousand ");

    out += numToWords(((n / 100) % 10), "hundred ");

    if (n > 100 && n % 100)
        out += "and ";

    out += numToWords((n % 100), "");

    if(out=="")
    out = "zero";

    return out;
}

int main()
{
    int n;
    cin >> n;

    if (n<0){
            cout << "negative ";
            n=-1*n;
            }
    cout << convertToWords(n) << endl;

    return 0;
}
