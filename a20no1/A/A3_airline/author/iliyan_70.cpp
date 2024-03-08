#include<iostream>
#include<vector>
using namespace std;
vector <int> a[100001];
int min1=100000,curr,ans[100001],fl;
void dfs (int vr, int fath, int dep) {
    if (dep>min1) {
       fl++;
       return ;
       }
    curr=max(curr,dep);
    int i;
    for (i=0; i<a[vr].size(); i++) {
        if (a[vr][i]==fath) continue;
        dfs(a[vr][i],vr,dep+1);
        if (fl!=0) return ;
        }
}
int main () {
    int n,i,x,y,min2,cnt=0;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n ;
    for (i=0; i<n-1; i++) {
        cin >> x >> y ;
        x--; y--;
        a[x].push_back(y);
        a[y].push_back(x);
        }
    for (i=0; i<n; i++) {
        curr=-1; fl=0;
        dfs(i,-1,0);
        if (fl==0) ans[i]=curr;
        else ans[i]=100000;
        min1=min(min1,ans[i]);
        }
    for (i=0; i<n; i++) {
            //cout << ans[i] << " ";
        if (min2>ans[i]) min2=ans[i], cnt=1;
        else if (min2==ans[i]) cnt++;
        } //cout << endl ;
    cout << cnt << endl ;
    for (i=0; i<n; i++) {
        if (ans[i]==min2) cout << i+1 << " ";
        }
    cout << endl ;
    return 0;
}
