#include<iostream>
#include<stdio.h>
using namespace std;
int a[200001],ans,n;
void erase1 (int ind) {
     int i;
     if (ind==0) {
        if (a[ind]!=a[ind+1]) ans--;
        }
     else if (ind==n-1) {
             if (a[ind]!=a[ind-1]) ans--;
             }
     else { if ((a[ind-1]!=a[ind])&&(a[ind]!=a[ind+1])) {
               ans--;
               if (a[ind-1]==a[ind+1]) ans--;
               } }
     for (i=ind; i<n-1; i++) {
         a[i]=a[i+1];
         }
     n--;
}
void insert1 (int ind, int col) {
     int i;
     if (ind==0) {
        if (a[ind]!=col) ans++;
        }
     else if (ind==n-1) {
             if (a[ind]!=col) ans++;
             }
     else { if ((a[ind-1]!=col)&&(col!=a[ind])) {
               ans++;
               if (a[ind-1]==a[ind]) ans++;
               } }
     for (i=n; i>ind; i--) {
         a[i]=a[i-1];
         }
     a[ind]=col;
     n++;
}
void change (int ind, int col) {
     if (ind==0) {
        if (a[ind]!=a[ind+1]) ans--;
        }
     else if (ind==n-1) {
             if (a[ind]!=a[ind-1]) ans--;
             }
     else { if ((a[ind-1]!=a[ind])&&(a[ind]!=a[ind+1])) {
               ans--;
               if (a[ind-1]==a[ind+1]) ans--;
               } }
     if (ind==0) {
        if (a[ind+1]!=col) ans++;
        }
     else if (ind==n-1) {
             if (a[ind-1]!=col) ans++;
             }
     else { if ((a[ind-1]!=col)&&(col!=a[ind+1])) {
               ans++;
               if (a[ind-1]==a[ind+1]) ans++;
               } }
     a[ind]=col;
}
int main () {
    int i,num,q,type,ind,col;
    scanf("%d",&n);
    for (i=0; i<n; i++) {
        scanf("%d",&a[i]);
        }
    scanf("%d",&q);
    ans=1;
    for (i=1; i<n; i++) {
        if (a[i]!=a[i-1]) ans++;
        }
    for (i=0; i<q; i++) {
        scanf("%d",&type);
        if (type==1) {
           scanf("%d",&ind);
           ind--;
           erase1(ind);
           }
        else if (type==2) {
                scanf("%d%d",&ind,&col);
                ind--;
                insert1(ind,col);
                }
        else if (type==3) {
                scanf("%d%d",&ind,&col);
                ind--;
                change(ind,col);
                }
        else printf("%d\n",ans);
        /*for (int j=0; j<n; j++) {
            printf("%d ",a[j]);
            }
        printf("\n");*/
        }
    return 0;
}
