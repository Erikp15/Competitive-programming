#include <iostream>
#include <vector>
using namespace std;
vector <long long> lev[3];
bool makeNewLev(int ind,long long &No,long long N=-1)
{bool b=false;
 ind%=3;
 int pr=(ind+2)%3;
 lev[ind].clear();
 lev[ind]=vector<long long>(2*lev[pr].size());
 long long z=lev[pr][lev[pr].size()-1]+1;
 for (long long i=0;i<lev[ind].size();i+=2) 
 {if (z==N) {No=i;
             b=true;
            }
  lev[ind][i]=z++;
 }
 for (long long i=1;i<lev[ind].size();i+=2)
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
 for (unsigned int i=0;i<lev[n].size();i++) cout<<lev[n][i]<<' ';
 cout<<endl;
}
void init()
{lev[0]=vector<long long>(1);
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
 prev=lev[pr][pn];
 nextL=lev[nx][nnl];
 nextR=lev[nx][nnr];
}
int main()
{long long N,prev,nextL,nextR;
 init();
 cin>>N;
 solve(N,prev,nextL,nextR);
 cout<<prev<<endl;
 cout<<nextL<<' '<<nextR<<endl;
 return 0;
}