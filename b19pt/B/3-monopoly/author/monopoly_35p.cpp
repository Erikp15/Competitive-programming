#include<iostream>
#include<stdio.h>
#include<vector>
#include<deque>
using namespace std;
vector <int> a[100001];
deque <int> vers;
int deg[100001],ans=0;
void rec () {
     if (vers.empty()==1) {
        ans++;
        return ;
        }
     int num=vers.size(),i,j,curr;
     //cnt++;
     //cout << "aaaaa " << vers.size() << " " << vers.front() << endl ;
     for (i=0; i<num; i++) {
         curr=vers.front();
         //cout << cnt1 << ": ";
         /*for (j=0; j<vers.size(); j++) {
            cout << vers[j]+1 << " ";
         } cout << endl ;*/
         for (j=0; j<a[curr].size(); j++) {
             deg[a[curr][j]]--;
             if (deg[a[curr][j]]==0) vers.push_back(a[curr][j]);
             }
         vers.pop_front();
         rec();
         //cout << cnt1 << ": ";
         for (j=0; j<a[curr].size(); j++) {
             if (deg[a[curr][j]]==0) vers.pop_back();
             deg[a[curr][j]]++;
             }
         vers.push_back(curr);
         /*for (j=0; j<vers.size(); j++) {
            cout << vers[j]+1 << " ";
         } cout << endl ;*/
         }
}
int main () {
    int n,m,i,x,y;
    cin >> n >> m ;
    for (i=0; i<m; i++) {
        scanf("%d%d",&x,&y);
        x--; y--;
        a[x].push_back(y);
        deg[y]++;
        }
    for (i=0; i<n; i++) {
        if (deg[i]==0) vers.push_back(i);
        }
    rec();
    cout << ans ;
    cout << endl ;
    return 0;
}
