#include <iostream>

using namespace std;

long long m,n,p,a,depth=0,q,numsolutions,maxq=0;
char currSolution[100000];
long long countofqs[100];

void rec(bool ispreviousP,int weightsofar,int depth,int qcounter){
    if(weightsofar>=n){
        countofqs[qcounter]++;
        if(qcounter>maxq) { maxq = qcounter; }
        if(qcounter==2) {
            for(long long i=0;i<depth;i++){
                cout<<currSolution[i]<<" ";
                if(currSolution[i]!='p' and currSolution[i]!='q'){
                    cout<<"niq"<<"("<< (int)currSolution[i]<<")";
                }
            }
            cout<<" " << weightsofar<<endl;
        }
        numsolutions++;
        return;
    }
    if(ispreviousP==true){
        currSolution[depth]='q';
        rec(false,weightsofar-q,depth+1,qcounter+1);
    }
    currSolution[depth]='p';
    rec(true,weightsofar+p,depth+1,qcounter);
    return ;
}
int main(){
    cin>>m>>n>>p>>q; n-=m;
    rec(false,0,0,0);
    for(long long i=0;i<=maxq;i++){
        cout<<i<<": "<<countofqs[i]<<endl;
    }
    cout<<numsolutions<<endl;
    return 0;
}
