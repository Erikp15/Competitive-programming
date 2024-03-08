#include<iostream>
using namespace std;

const int N=1000000;
int n;
int a[N+1];
int s;

int main()
{
  cin >> n;
  for(int i=1;i<=n;i++) cin >> a[i];
  cin >> s;
  
  for(int i=1;i<=n;i++)
  for(int j=i;j<=n;j++)
  {
    if(a[i]+a[j]==s)
    {
      cout << i << " " << j << endl; 
      return 0;               
    }        
  }
  cout << "0 0" << endl;
  return 0;
}
