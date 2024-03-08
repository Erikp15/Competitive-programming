#include<iostream>
#include<stdlib.h>
#include<vector>
#include<map>
using namespace std;
vector <int> a[100001];
map <pair <int, int>, bool> edges;
int used[100001],max1[100001],ans[100001];
void dfs (int vr, int fath) {
    used[vr]=1; max1[vr]=-1;
    int i;
    for (i=0; i<a[vr].size(); i++) {
        if (a[vr][i]==fath) continue;
        if (used[a[vr][i]]==1) {
           cerr << "Error3!\n";
           exit(0);
           }
        dfs(a[vr][i],vr);
        max1[vr]=max(max1[vr],max1[a[vr][i]]+1);
        }
    if (max1[vr]==-1) max1[vr]=0;
}
void dfs2 (int vr, int fath, int up) {
    ans[vr]=max1[vr];
    int i,max2=up+1,max3=-1;
    if (fath!=-1) ans[vr]=max(ans[vr],up);
    for (i=0; i<a[vr].size(); i++) {
        if (a[vr][i]==fath) continue;
        if (max2<=max1[a[vr][i]]+2) {
           max3=max2;
           max2=max1[a[vr][i]]+2;
           }
        else if (max3<max1[a[vr][i]]+2) max3=max1[a[vr][i]]+2;
        }
        //cout << vr << " " << max2 << " " << max3 << endl ;
    for (i=0; i<a[vr].size(); i++) {
        if (a[vr][i]==fath) continue;
        if (max2==max1[a[vr][i]]+2) dfs2(a[vr][i],vr,max3);
        else dfs2(a[vr][i],vr,max2);
        }
}
int main () {
    int n,i,x,y,min1,cnt=0;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n ;
    for (i=0; i<n-1; i++) {
        cin >> x >> y ;
        x--; y--;
        if ((x==y)||(x<0)||(x>=n)||(y<0)||(y>=n)) {
           cerr << "Error1!\n";
           exit(0);
           }
        a[x].push_back(y);
        a[y].push_back(x);
        if (x>y) swap(x,y);
        if (edges.count({x,y})==1) {
           cerr << "Error2!\n";
           exit(0);
           }
        edges[{x,y}]=1;
        }
    dfs(0,-1);
    for (i=0; i<n; i++) {
        if (used[i]==0) {
           cerr << "Error3!\n";
           exit(0);
           }
        }
    dfs2(0,-1,0);
    for (i=0; i<n; i++) {
            //cout << ans[i] << " ";
        if (min1>ans[i]) min1=ans[i], cnt=1;
        else if (min1==ans[i]) cnt++;
        } //cout << endl ;
    cout << cnt << endl ;
    for (i=0; i<n; i++) {
        if (ans[i]==min1) cout << i+1 << " ";
        }
    cout << endl ;
    return 0;
}
