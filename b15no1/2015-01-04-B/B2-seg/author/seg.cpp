#include<iostream>
using namespace std;

int n;
const int M=10001;
int a[M];

int main()
{
  cin >> n;
  int x,y;
  for(int i=1;i<=n;i++)
  { cin >> x >> y;
    for(int j=x;j<y;j++) a[j]=1;
  }

  int c=0;
  int d=0;
  int max=0;
  for(int i=0;i<M;i++)
    if(a[i]==0)
     {if(d>0)
        { c++;
          if(max<d) max=d;
          d=0;
        }
     }
    else d++;

  cout << c << " " << max << endl;
  return 0;
}

