#include <iostream>
#include <cmath>

using namespace std;

struct TToc{
	int x,y;
};
struct TOts {
	TToc t1,t2;
};
TOts a,b;

int Min;

void Podr (TOts &t) {
    if (t.t1.y == t.t2.y) {
    	if (t.t1.x>t.t2.x) swap (t.t1,t.t2);
    }
    else
    	if (t.t1.y>t.t2.y) swap (t.t1,t.t2);
}

int MR (TToc p,TToc q) {
	return abs(p.x-q.x)+abs(p.y-q.y);
}

bool Hor (TOts t){
	return (t.t1.y == t.t2.y);
}
int main() {
 cin>>a.t1.x>>a.t1.y>>a.t2.x>>a.t2.y;
 cin>>b.t1.x>>b.t1.y>>b.t2.x>>b.t2.y;
	Podr(a); Podr(b);
	if (Hor(a) && Hor(b)) {
		if (a.t1.x > b.t1.x) swap(a,b);
		if (a.t2.x<b.t1.x) Min=MR(a.t2,b.t1);
		else
		Min=abs(a.t1.y-b.t1.y);
		cout<<Min<<endl;
  return 0;
	}
	if ((!Hor(a)) && (!Hor(b))) {
		if (a.t1.y > b.t1.y) swap(a,b);
		if (a.t2.y<b.t1.y) Min=MR(a.t2,b.t1);
		else
		Min=abs(a.t1.x-b.t1.x);
		cout<<Min<<endl;
			return 0;
	}
 if (Hor(b)) swap(a,b);
 if (b.t1.y<=a.t1.y && a.t1.y<=b.t2.y && a.t1.x<=b.t1.x && b.t1.x<=a.t2.x) {
  Min=0;
  cout<<Min<<endl;
  return 0;			
 }
 if (b.t1.y<=a.t2.y && a.t2.y <= b.t2.y) {
  Min=min(abs(a.t1.x-b.t1.x),abs(a.t2.x-b.t1.x));
  cout<<Min<<endl;
  return 0;
 }
 if (a.t1.y<=b.t1.y && b.t1.y <= a.t2.y) {
  Min=min(abs(a.t1.y-b.t1.y),abs(a.t1.y-b.t2.y));
  cout<<Min<<endl;
  return 0;
 }
		Min=min(MR(a.t1,b.t2),MR(a.t1,b.t1));
		Min=min(Min,MR(a.t2,b.t1));
		Min=min(Min,MR(a.t2,b.t2));    
  cout<<Min<<endl;
  return 0;
}
/*
3 6 5 6 
8 6 9 6
3
8 6 9 6
3 6 5 6 
3
9 6 8 6
3 6 5 6 
3
9 6 8 6
5 6 3 6
3
3 6 6 6
5 6 9 6
0
5 6 9 6
3 6 6 6
0
5 6 9 6
6 6 3 6
0
9 6 5 6 
6 6 3 6
0
4 5 8 5
6 7 9 7
3
6 7 9 7
4 5 8 5
3
9 7 6 7
8 5 4 5 
3
9 7 6 7
4 5 8 5
3
4 5 8 5
6 7 9 7
2
6 7 9 7
4 5 8 5
2
8 5 4 5 
6 7 9 7
2
4 5 8 5
9 7 6 7
2
4 5 7 5
7 5 9 5
0
7 5 9 5
4 5 7 5
0
7 5 4 5
7 5 9 5
0
4 5 7 5
9 5 7 5 
0
3 8 7 8
7 2 9 2
6
7 2 9 2
3 8 7 8
6
7 8 3 8
7 2 9 2
6
3 8 7 8
9 2 7 2
6
2 7 6 7
8 3 9 3
5
6 7 2 7 
8 3 9 3
5
8 3 9 3
2 7 6 7
5
2 7 6 7
9 3 8 3
5
5 6 5 8
9 2 9 4
6
9 2 9 4
5 6 5 8
6
5 8 5 6
9 4 9 2 
6
5 8 5 6 
9 2 9 4
6
8 2 8 7
3 6 3 9
5
3 6 3 9
8 2 8 7
5
3 9 3 6
8 2 8 7
5
8 2 8 7
3 9 3 6
5
5 2 5 7
5 4 5 9
0
5 4 5 9
5 2 5 7
0
5 4 5 9
5 2 5 7
0
5 9 5 4 
5 7 5 2
0
3 5 3 9
7 2 7 8
0
7 2 7 8
3 5 3 9
0
7 8 7 2
3 9 3 5
0
7 2 7 8
3 9 3 5
0
1 9 5 9
9 3 9 7
6
9 3 9 7
1 9 5 9
6
9 7 9 3
1 9 5 9
6
1 9 5 9
9 7 9 3
6
1 1 5 1
9 7 9 3
4
5 1 1 1
9 7 9 3
4
1 1 5 1
9 3 9 7 
4
9 7 9 3
1 1 5 1
4
2 7 5 7
8 2 8 9
3
8 2 8 9
2 7 5 7
3
5 7 2 7
8 2 8 9
3
2 7 5 7
8 9 8 2 
3
8 2 8 9
11 7 16 7
3
11 7 16 7
8 2 8 9
3
16 7 11 7
8 2 8 9
3
8 2 8 9
16 7 11 7
3




*/

