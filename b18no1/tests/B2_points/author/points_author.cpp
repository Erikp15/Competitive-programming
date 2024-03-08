#include <iostream>
#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;

struct TP{
	int x,y;
};

struct TPr{
	int x,x1,y;
};

int n, m, Otg=0;
TP t[110002];
TPr pr[11002];


bool fff(TP t1,TP t2) {
	if (t1.x<t2.x)	return true;
	else
	if (t1.x == t2.x)	{
		return (t1.y<=t2.y);
	}
	else
	return false;
}

int main() {

int w,h,i;
    cin >> n >> m;
    cin >> pr[1].x1 >> pr[1].y;
    pr[1].x=0;
    for (i = 2; i <= n; i++) {
        cin >> w >> pr[i].y;
        pr[i].x=pr[i-1].x1;
		pr[i].x1=pr[i].x+w;
    }

    for (i = 1; i <= m; i++)
		cin >> t[i].x >> t[i].y;

    sort(t+1, t + m + 1,fff);
//
int bt=1,bPr=1;

	while (1) {
		if (t[bt].x>pr[bPr].x1) {
			while (t[bt].x>pr[bPr].x1) bPr++;
			if (bPr>n) break;
		}
		if ((t[bt].x==pr[bPr].x1) and (t[bt].y>pr[bPr].y))
			bPr++;
		if (bPr>n) break;
		if (pr[bPr].x<=t[bt].x and t[bt].x<=pr[bPr].x1 and t[bt].y<=pr[bPr].y) {
			Otg++;
		}
		bt++;
		if (bt>m) break;
	}
	cout<<Otg<<endl;
    return 0;
}
