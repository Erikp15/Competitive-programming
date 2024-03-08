#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<queue>
using namespace std;
int perm[100001],ind[100001];
vector <int> a[100001];
int main () {
    int n,m,i,j,x,y,fl,ans=0;
    cin >> n >> m ;
    for (i=0; i<m; i++) {
        scanf("%d%d",&x,&y);
        x--; y--;
        a[x].push_back(y);
        }
    for (i=0; i<n; i++) {
        perm[i]=i;
        }
    for (;;) {
        for (i=0; i<n; i++) {
            ind[perm[i]]=i;
            }
        fl=0;
        for (i=0; i<n; i++) {
            for (j=0; j<a[i].size(); j++) {
                if (ind[i]>ind[a[i][j]]) {
                   fl++;
                   break;
                   }
                }
            if (fl!=0) break;
            }
        if (fl==0) ans++;
        if (next_permutation(perm,perm+n)==0) break;
        }
    cout << ans ;
    cout << endl ;
    return 0;
}
