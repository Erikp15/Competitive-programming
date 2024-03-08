#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;
const long long int mod=1e9+7;
long long int ans[100001],fact[100001];
vector <int> a[100001],tree[100001];
queue <int> vers;
int deg[100001],br[100001];
void rec (int vr) {
     ans[vr]=1; br[vr]=1;
     int i;
     for (i=0; i<tree[vr].size(); i++) {
         rec(tree[vr][i]);
         br[vr]+=br[tree[vr][i]];
         ans[vr]*=ans[tree[vr][i]];
         }
     long long int num=fact[br[vr]-1];
     //cout << ans[vr] << " " << fact[br[vr]-1] << " ";
     for (i=0; i<tree[vr].size(); i++) {
         num/=fact[br[tree[vr][i]]];
         }
     ans[vr]*=num;
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
    fact[0]=1;
    for (i=1; i<=n; i++) {
        fact[i]=fact[i-1]*i;
        }
    rec(0);
    cout << ans[0]%mod ;
    cout << endl ;
    return 0;
}
