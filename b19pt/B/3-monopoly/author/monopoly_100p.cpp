#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;
const long long int mod=1e9+7;
long long int ans[100001],fact[100001],div1[100001];
vector <int> a[100001],tree[100001];
queue <int> vers;
int deg[100001],br[100001];
long long int exp (long long int base, int pow) {
    if (pow==1) return base;
    long long int res=exp((base*base)%mod,pow/2);
    if (pow%2!=0) res*=base, res%=mod;
    return res;
}
void rec (int vr) {
     ans[vr]=1; br[vr]=1;
     int i;
     for (i=0; i<tree[vr].size(); i++) {
         rec(tree[vr][i]);
         br[vr]+=br[tree[vr][i]];
         ans[vr]*=div1[br[tree[vr][i]]];
         ans[vr]%=mod;
         ans[vr]*=ans[tree[vr][i]];
         ans[vr]%=mod;
         }
     ans[vr]*=fact[br[vr]-1];
     ans[vr]%=mod;
     //cout << vr << " " << ans[vr] << endl ;
}
int main () {
    int n,m,i,x,y;
    cin >> n >> m ;
    for (i=0; i<m; i++) {
        scanf("%d%d",&x,&y);
        a[x].push_back(y);
        deg[y]++;
        }
    for (i=1; i<=n; i++) {
        if (deg[i]==0) {
           a[0].push_back(i);
           deg[i]++;
           }
        }
    vers.push(0);
    for (;;) {
        if (vers.empty()==1) break;
        x=vers.front();
        for (i=0; i<a[x].size(); i++) {
            deg[a[x][i]]--;
            if (deg[a[x][i]]==0) {
               tree[x].push_back(a[x][i]);
               vers.push(a[x][i]);
               }
            }
        vers.pop();
        }
    fact[0]=1; div1[0]=1;
    for (i=1; i<=n; i++) {
        fact[i]=fact[i-1]*i;
        fact[i]%=mod;
        div1[i]=div1[i-1]*exp(i,mod-2);
        div1[i]%=mod;
        }
    rec(0);
    cout << ans[0] ;
    cout << endl ;
    return 0;
}
