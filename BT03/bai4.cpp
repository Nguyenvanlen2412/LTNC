#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    string SS[100][100];
    for (int i=0; i<n; i++)
    for (int j=0; j<m; j++)
        cin >> SS[i][j];
    for (int i=0; i<n; i++)
    for (int j=0; j<m; j++)
    {
        if(SS[i][j]==".")
        {
            int x=0;

            if(i>0 && SS[i-1][j]=="*")x++;
            if(i>0 && j>0 && SS[i-1][j-1]=="*")x++;
            if (i>0 && j<m-1 && SS[i-1][j+1]=="*")x++;
            if(j>0&& SS[i][j-1]=="*") x++;
            if(j<m-1&& SS[i][j+1]=="*") x++;
            if(i<n-1 && j>0 && SS[i+1][j-1]=="*")x++;
            if(i<n-1 && SS[i+1][j]=="*")x++;
            if(i<n-1 && j<m-1 && SS[i+1][j+1]=="*")x++;

            SS[i][j]=to_string(x);
        }
        else continue;
    }
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
            cout << SS[i][j] << " ";
        cout << endl;
    }
    return 0;
}
