#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
using namespace std;

int n, a[200001], ba,bN;

void TrieA(int nn){
int i;
	for (i=nn; i<=ba-1;i++) a[i]=a[i+1];
	a[ba]=0;
	ba--;
}

void SmeniA(int nn, int cc){
	a[nn]=cc;
}

int SmetniA(){
int br=0, i;
	br=1;
	for (i=2; i<=ba; i++)
		if (a[i]!=a[i-1]) br++;
	return br;	
}

int WmykniA(int nn, int cc){
int i;
	ba++;
	for (i=ba; i>=nn+1; i--)
		a[i]=a[i-1];
	a[nn]=cc;	
}

int main (){
int i,k, br1,t,k1,k2,k3;
//  freopen("bal.12.in", "r", stdin);
//  freopen("bal.12.sol", "w", stdout);
	cin>>n;
	cin>>k;
	ba=n;
	a[1]=k;
	for (i=2; i<=n; i++){
		cin>>a[i];
	}
	cin>>t;
	for (i=1;i<=t;i++){
		cin>>k;
		if (k==1){
			cin>>k1;
			TrieA(k1);	
		}
		else
		if (k==2){
			cin>>k1>>k2;
			WmykniA(k1,k2);
		}
		else
		if (k==3){
			cin>>k1>>k2;
			SmeniA(k1,k2);
		}
		else
		if (k==4){	
			br1=SmetniA();
			printf("%d\n",br1);	
		}
	}

  	return 0;
}

