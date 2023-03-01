#include <iostream>
using namespace std;
int main()
{
    string s;
    char a[2], b[3];
    cin >> s;
    for (int i=0;i<s.size();i++){
             a[0] =s[i];
        for (int j=0;j<s.size();j++){
            a[1] = s[j];
            for (int k=0;k<2;k++)
                cout << a[k];
            cout << ' ';
        }
    }
    for (int i=0;i<s.size();i++){
             b[0] =s[i];
        for (int j=0;j<s.size();j++){
            b[1] = s[j];
            for (int k=0;k<s.size();k++){
                b[2]=s[k];
                for (int h=0;h<3;h++)
                    cout << b[h];
                cout << ' ';
            }
        }
    }
    return 0;
}
