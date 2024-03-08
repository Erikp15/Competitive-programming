#include<iostream>
using namespace std;

const int N=1000000;
int n;
int a[N+1];
int s;
int p[2002];

int main()
{
  cin >> n;
  for(int i=1;i<=n;i++) cin >> a[i];
  cin >> s;
  for(int j=1;j<=n;j++)
  {
    int v=s-a[j];
    if(v>0)
    if(p[v]==0)
     p[v]=j;
  }
  for(int i=1;i<=n;i++)
   if(p[a[i]]>0)
    {
      cout << i << " " << p[a[i]] << endl;
      return 0;
    }
  cout << "0 0" << endl;
  return 0;
}
