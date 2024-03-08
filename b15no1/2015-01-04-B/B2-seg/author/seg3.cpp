#include<iostream>
#include<algorithm>
using namespace std;

int n;
const int M=1001;
int l[M], r[M];

int main()
{
  cin >> n;
  for(int i=0; i<n; i++)
    cin >> l[i] >> r[i];
  l[n]=10000; r[n]=10001;
  sort(l, l+n+1);
  sort(r, r+n+1);
  int first=l[0], second=r[0], max=0, cnt=0;
  for(int i=1; i<=n; i++)
  {
      if(l[i]<=r[i-1])
        second=r[i];
      else
     {
        cnt++;
        if (second-first>max) max=second-first;
        first=l[i];
        second=r[i];
    }
  }
  cout << cnt << " " << max << "\n";

  return 0;


}

