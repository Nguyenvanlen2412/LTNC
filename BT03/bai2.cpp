#include <iostream>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int i=0, j=s.size();
    while (i<j-1){
        if(s[i] != s[j-1]) {
            cout << "no";
            return 0;
        }
        i++;
        j--;
    }
    cout << "yes";
    return 0;
}
