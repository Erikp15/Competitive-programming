#include<iostream>
#include<set>
using namespace std;

int n;

void reduce(int &x, int &y)
{
  int x0=x;
  int y0=y;
  while(x!=y)
   if(x>y){x=x-y;}
   else y=y-x;
  int d=x;
  x=x0/d;
  y=y0/d;
}

set<pair<int, int> > s;
pair<int, int> xy;

int main()
{
   cin >> n;
   int cv=0;
   int ch=0;
   for(int i=1;i<=n;i++)
   {
     int x1, y1, x2, y2;
     cin >> x1 >> y1 >> x2 >> y2;
     if(x1>x2) {swap(x1,x2); swap(y1,y2);}
     int x=x2-x1;
     int y=y2-y1;
     if(x==0){cv=1; continue;}
     if(y==0){ch=1; continue;}
     int e=1; if(y<0){y=-y;e=-1;}
     reduce(x,y);
     y=e*y;
     xy.first=x;
     xy.second=y;
     s.insert(xy);
   }
   cout << s.size()+cv+ch << endl;
}
