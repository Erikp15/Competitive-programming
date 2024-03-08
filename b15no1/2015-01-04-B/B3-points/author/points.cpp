#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
struct Toc {
	int k;
	int f,n;
};
Toc t[300003];
int N,M,bt, p[100001];

bool fff (Toc t1, Toc t2) {
	if (t1.k<t2.k) return true;
	if (t1.k>t2.k) return false;
    return (t1.f>t2.f);
}

int main () {
    int i, br=0;
    int l,r;
	bt=0;
	cin>>N>>M;
	for (i=1;i<=N;i++) {
		scanf("%i %i",&l,&r);
		if (r<l) swap (l,r);
		bt++;
		t[bt].k=l; t[bt].f=1;
		t[bt].n=111111;
		bt++;
		t[bt].k=r; t[bt].f=-1;
		t[bt].n=111111;
	}
	for (i=1;i<=M;i++) {
		scanf("%i",&l);
		bt++;
		t[bt].k=l; t[bt].f=0;
		t[bt].n=i;
	}
	sort(t+1,t+bt+1,fff);
	for (i=1; i<=bt;i++){
		if (t[i].f==0) {
			p[t[i].n]=br;
		}
		else {
			br+=t[i].f;
		}
	}
	for (i=1; i<M;i++)
		printf("%i ",p[i]);
	printf("%i\n",p[M]);
    return 0;
}
/*
9 17
1 10
7 3
5 20
7 15
7 25
30 10
10 35
15 30
30 40
0 1 2 3 5 6 7 10 12 15 20 27 30 32 35 40 45


3 4
2 5
7 3
5 10
4 11 5 8

*/
