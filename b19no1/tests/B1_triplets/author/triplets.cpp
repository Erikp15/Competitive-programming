#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

set<int> s;

int main()
{

 int n;
 cin >> n;

 for(int i=0;i<n;i++) {int v; cin >> v; s.insert(v);}

 vector<int>a;
 a.assign(s.begin(),s.end());
 sort(a.begin(),a.end());
 n=a.size();

 set<set<int> > r;

 for(int i=0;i<n;i++)
 for(int j=i+1;j<n;j++)
 for(int k=0;k<n;k++)
 if(k !=i && k != j)
 {
  if(a[k]<=a[j]-a[i]) continue;
  if(a[k]>=a[j]+a[i]) break;
  {
    set<int> p;
    p.insert(i);p.insert(j);p.insert(k);
    r.insert(p);
  }
 }
 cout << r.size() << endl;
}
