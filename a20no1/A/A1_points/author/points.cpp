#include<iostream>
#include<cstdlib>
#include<set>
using namespace std;

int n;

set<pair<int, int> >s;


int nod(int a, int b)
{
  while(b>0)
  {
    int c=a%b;
    a=b;
    b=c;
  }
  return a;
}


void line(int  x1, int y1, int x2, int y2)
{

  if(x1>x2) {swap(x1,x2); swap(y1,y2);}

  int x=x2-x1;
  int y=abs(y1-y2);

  int d=nod(x,y);

  int kx=x/d;
  int ky=y/d;
  if(y1>y2) ky=-ky;

  for(int k=0;k<=d;k++)
  {
   s.insert(make_pair(x1+k*kx, y1+k*ky));
  }

}

int main()
{
  cin >> n;
  for(int i=1;i<=n;i++)
  {
    int  x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    line(x1,y1,x2,y2);
  }

  cout << s.size() << endl;
}

