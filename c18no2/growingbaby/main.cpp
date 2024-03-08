#include <iostream>

using namespace std;

long long fac(long long n){
    long long res=1;
    for(long long i=1;i<=n;i++){
        res*=i;
        //res=res % 1073741824;
    }
    return res;
}
long long choose(int n,int q){
    if(q<0) return 0;
    return (fac(n)/fac(n-q)) / fac(q);
}

long long m,n,p,a,depth=0,q,numsolutions,maxq=0;
long long numberofvariants=0,numberofpsinN,maximumpossibleval,MAXnumberofqs,numberofps,pascallines;
long long diff;
char currSolution[100000];
long long countofqs[100];
const long long MAX_size=7900;
long long pascaltriangle[MAX_size][MAX_size];

void rec(bool ispreviousP,int weightsofar,int depth,int qcounter){
    if(weightsofar>=diff){
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
void initalizepascal(){
    for(long long i=0;i<MAX_size;i++){
        for(long long j=0;j<MAX_size;j++){
            if(i==0 or j==0)
                {pascaltriangle[i][j]=1;}
            else
                pascaltriangle[i][j]=(pascaltriangle[i-1][j]+pascaltriangle[i][j-1])%(2<<29);
        }
    }
}
void exhaustive(){
    rec(false,0,0,0);
    cout << "Exhaustive solution" << endl;
    for(long long i=0;i<=maxq;i++){
        cout<<i<<": "<<countofqs[i]<<endl;
    }
    cout<<numsolutions<<endl;
    return;
} // void exhaustive

void optimal(){
    MAXnumberofqs=(diff-p+(p-q-1))/(p-q);
    if(MAXnumberofqs<0){MAXnumberofqs=0;}
    pascallines=MAXnumberofqs+1;
    //cout << "Optimal solution MAXQ:" << MAXnumberofqs << " diff:" << diff << endl;
    for(long long i=0;i<=MAXnumberofqs;i++){
        long long numberofPs = (diff + q*i + p-1)/p;
        //long long allpermsofiqs=(fac(pascallines-1)/fac(pascallines-1-i))/fac(i);
        long long allpermsofiqs=pascaltriangle[numberofPs-1-i][i]%(2<<29);
        //choose(numberofPs-1,i);
        //long long allremovedpermsofq=(fac(pascallines-2)/fac(pascallines-2-(i-1)))/fac(i-1);
        long long allremovedpermsofq=0;
        if(((numberofPs-1)*p-(i-1)*q)%(2<<29)>=diff){
            allremovedpermsofq=pascaltriangle[numberofPs-2-(i-1)][i-1]%(2<<29);
            //choose(numberofPs-2,i-1);
        }
        //cout << i <<": numP:" << numberofPs << " ";
        //cout<<"add: " << allpermsofiqs<<" ";
        //cout<<"rem: " << allremovedpermsofq<<endl;
        numberofvariants+=(allpermsofiqs-allremovedpermsofq)%(2<<29);
    }
    cout<<numberofvariants%(2<<29)<<endl;
}

int main(){
    initalizepascal();
    if(0){
        cin>>m>>n>>p>>q;
    } else {
        switch (1) {
           case 1: m=0; n=12; p=5; q=1; break;
           case 2: m=0; n=400; p=50; q=25; break;
           case 3: m=0; n=160; p=20; q=3; break;
           case 4: m=3250; n=5000; p=99; q=43; break;
           case 5: m=2000; n=10000; p=100; q=99; break;
           default: m=4500; n=4560; p=20; q=7; break;
        }
    }
    diff=n-m;
    //exhaustive();
    optimal();
    return 0;
}

