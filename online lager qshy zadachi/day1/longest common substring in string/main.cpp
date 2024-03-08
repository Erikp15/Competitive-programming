#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

int max(int a, int b);

/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcs(string X, string Y, int m, int n)
{
    if (m == 0 || n == 0)
        return 0;
    if (X[m - 1] == Y[n - 1])
        return 1 + lcs(X, Y, m - 1, n - 1);
    else
        return max(lcs(X, Y, m, n - 1), lcs(X, Y, m - 1, n));
}

/* Utility function to get max of 2 integers */
int max(int a, int b)
{
    return (a > b) ? a : b;
}

/* Driver program to test above function */
int main(){
    string X,Y;
    cin>>X>>Y;
    int m = X.length();
    int n = Y.length();

    printf(lcs(X, Y, m, n));

    return 0;
}















































/*
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int length[101][101];
int main(){
    string a,b;
    cin>>a>>b;
    int alength=0,blength=0;
    int l=0;
    length[0][0]=0;
    length[1][1]=0;
    for(int j=1;j<a.length()+1;j++){
        for(int i=1;i<b.length()+1;i++){
            if(a[j]==b[i]){
                length[j][i]=length[j][i-1]+1;
            }else{
                length[j][i]=length[j][i-1];
            }
        }
    }
    for(int i=1;i<a.length()+1;i++){
        for(int j=1;j<b.length()+1;j++){
            cout << length[i][j] << " ";
        }
        cout<<endl;
    }
    return 0;
}
*/
