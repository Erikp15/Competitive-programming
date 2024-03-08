#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
int game[100][2];
vector <int> ans;
int main () {
    int n,i,j,num1,num2,fl;
    cin >> n ;
    for (i=0; i<n; i++) {
        cin >> game[i][0] >> game[i][1] ;
        }
    for (i=1; i<(10*game[0][1]+game[0][0])/7; i++) {
        if (i>10000) break;
        for (j=0; j<n; j++) {
            if (game[j][0]<i) break;
            num1=7*i-game[j][0];
            num2=game[j][1];
            if (num1<i) break;
            fl=0;
            for (;;) {
                if ((num1==0)&&(num2==0)) break;
                if ((num1==0)||(num2==0)) {
                   fl=0;
                   break;
                   }
                if (num1%10==num2%10) fl++;
                num1/=10; num2/=10;
                }
            if (fl!=1) break;
            }
        if (j==n) ans.push_back(i);
        }
    cout << ans.size() << endl ;
    for (i=0; i<ans.size(); i++) {
        printf("%d ",ans[i]);
        }
    cout << endl ;
    return 0;
}
