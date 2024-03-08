#include <iostream>
#include <cmath>
using namespace std;

long long a,b,a1,b1,a2,b2;

void init()
{ cin >> a  >> b;
  cin >> a1 >> b1;
  cin >> a2 >> b2;

  // долен ляв - горен десен
  if(a1>a2) swap(a1,a2);
  if(b1>b2) swap(b1,b2);
}


long long dist(long long x,  long long y,
               long long x1, long long y1,
               long long x2, long long y2)
{
  if(x1<=x && x<=x2 && y1<=y && y<=y2)
    return 0; // скакалецът е на поляната

  if(x1<=x && x<=x2) // северно или южно от поляната
    return min(abs(y1-y),abs(y2-y));

  if(y1<=y && y<=y2) // западно или източно от поляната
    return min(abs(x1-x),abs(x2-x));

  // търсим най-близкия връх
  long long r1 = (x1-x)*(x1-x) + (y1-y)*(y1-y);
  long long r2 = (x2-x)*(x2-x) + (y1-y)*(y1-y);
  long long r3 = (x1-x)*(x1-x) + (y2-y)*(y2-y);
  long long r4 = (x2-x)*(x2-x) + (y2-y)*(y2-y);

  long double r = min(min(r1,r2),min(r3,r4));
  long long d = ceil(sqrt(r));
  return d;
}

int main()
{ init();

  cout << dist(a,b,a1,b1,a2,b2) << endl;

  return 0;
}
