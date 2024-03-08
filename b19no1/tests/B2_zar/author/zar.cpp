#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>

using namespace std;
struct TTUmn {
	int a[10001],b;
};

struct TDChis {
	int b, a[7];
};

TTUmn v1,v2;
int N;
int sum[10001],fs[10001],tu[10001];
TDChis ch1,ch2;


int VyrniBrCif(int cc) {
	int br=0;

	while (cc>0)  {
		cc=cc/10;
		br++;
	}
	return br;
}

void NuliraV(TTUmn &vv) {
	int i;
	for (i=1; i<= vv.b; i++) vv.a[i]=0;
	vv.b=0;
}

void ObrChis(int cc,TDChis &mm) {
	int br=0;
	while (cc>0) {
		br++;
		mm.a[br]=cc%10;
		cc=cc/10;
	}
	mm.b=br;
}

bool Srawni() {
	bool Fl;
	int i,br;
	br=0;
	Fl=false;
	for (i=1; i<= ch1.b; i++)
		if (ch1.a[i]==ch2.a[i])
			br++;
	if (br==1) Fl=true;
	return Fl;
}

void Resh() {
	int i,j,k,c1,fc,brCfc,brCRaz,cRaz;

	for (i=1; i<=10001; i++) tu[i]=i*7;
	NuliraV(v1);
	c1=sum[1];
	fc=fs[1];
	brCfc=VyrniBrCif(fc);
	ObrChis(fc,ch1);
	for (j=1; j<= 10000; j++) {
		if (j<=c1 && c1<=6*j) {
			if (tu[j]-c1>0) {
				cRaz=tu[j]-c1;
				if (j<=cRaz && cRaz<=6*j) {
					brCRaz=VyrniBrCif(cRaz);
					if (brCRaz==brCfc) {
						ObrChis(cRaz,ch2);
						if (Srawni()) {
							v1.b++;
							v1.a[v1.b]=j;
						}
					}
				}
			}
		}
	}

	for (i=2; i<= N; i++) {
		NuliraV(v2);
		c1=sum[i];
		fc=fs[i];
		brCfc=VyrniBrCif(fc);
		ObrChis(fc,ch1);
		for (k=1; k<= v1.b; k++) {
			j=v1.a[k];
			if (j<=c1 && c1<=6*j) {
				if (tu[j]-c1>0) {
					cRaz=tu[j]-c1;
					if (j<=cRaz && cRaz<=6*j) {
						brCRaz=VyrniBrCif(cRaz);
						if (brCRaz==brCfc) {
							ObrChis(cRaz,ch2);
							if (Srawni()) {
								v2.b++;
								v2.a[v2.b]=j;
							}
						}
					}
				}
			}
		}
		NuliraV(v1);
		for (k=1; k<= v2.b; k++) v1.a[k]=v2.a[k];
		v1.b=v2.b;
		if (v1.b==1)  break;
	}

}

int main() {
	int i;
	cin>>N;
	for (i=1; i<=N; i++) cin>>sum[i]>>fs[i];
	Resh();
	cout<<v1.b<<endl;
	for (i=1; i<=v1.b; i++)
		cout<<v1.a[i]<<" ";
	return 0;
}
