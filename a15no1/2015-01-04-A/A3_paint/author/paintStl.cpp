#include <iostream>
using namespace std;
long long lev[3][20000000],cnt[3];
bool makeNewLev(int ind,long long &No,long long N=-1)
{bool b=false;
 int pr=(ind+2)%3;
 cnt[ind]=2*cnt[pr];
 long long z=lev[pr][cnt[pr]-1]+1;
 for (long long i=0;i<cnt[ind];i+=2) 
 {if (z==N) {No=i;
             b=true;
            }
  lev[ind][i]=z++;
 }
 for (long long i=1;i<cnt[ind];i+=2)
 {if (z==N) {No=i;
             b=true;
            }
  lev[ind][i]=z++;
 }
 return b;
}
bool makeNewLev(int ind)
{long long t;
 return makeNewLev(ind,t,-1);
}
void showLev(int n)
{n%=3;
 cout<<"Lev "<<n<<": ";
 for (unsigned int i=0;i<cnt[n];i++) cout<<lev[n][i]<<' ';
 cout<<endl;
}
void init()
{cnt[0]=1;
 lev[0][0]=0;   
}
void solve(long long N, long long &prev,long long &nextL,long long &nextR)
{long long No;
 int ind=0,pr,nx;
 int pn,nnl,nnr;
 do ind=(ind+1)%3; while (!makeNewLev(ind,No,N));
 pr=(ind+2)%3;
 nx=(ind+1)%3;
 makeNewLev(nx);    
 pn=No>>1;
 nnl=No<<1;
 nnr=nnl+1; 
/*
for(int i=0;i<3;i++) showLev(i);
cout<<"No="<<No<<endl;
cout<<"ind="<<ind<<endl;
cout<<"prev. level index: "<<pr<<endl;
cout<<"next level index: "<<nx<<endl;
cout<<"lev["<<pr<<"]["<<pn<<"]="<<lev[pr][pn]<<endl;
cout<<"lev["<<nx<<"]["<<nnl<<"]="<<lev[nx][nnl]<<endl;
cout<<"lev["<<nx<<"]["<<nnr<<"]="<<lev[nx][nnr]<<endl;
showLev(pr);
*/
 prev=lev[pr][pn];
//showLev(nx);
 nextL=lev[nx][nnl];
 nextR=lev[nx][nnr];
}
int main()
{long long N=37,prev,nextL,nextR;
 cin>>N;
 init();
 solve(N,prev,nextL,nextR);
 cout<<prev<<endl;
 cout<<nextL<<' '<<nextR<<endl;
 return 0;
}