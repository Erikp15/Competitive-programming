#include <iostream>

using namespace std;

int main(){
    const long long goog = 1000000007;
    long long n,res=0,countt=0,fac[59];
    cin>>n;
    fac[0]=1;
    for(int i=1;i<=50;i++){
        fac[i]=(fac[i-1]*i)%goog;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j==i){continue;}
            for(int k=1;k<=n;k++){
                if(k==i or k==j){continue;}
                for(int m=1;m<=n;m++){
                    if(m==i or m==j or m==k){continue;}
                    int addition=0,mult=1,digcount=0,l=0,currentdig[]={m,k,j,i};
                    while(digcount<4){
                        if(currentdig[l]<10){
                            addition+=currentdig[l]*mult;
                            digcount++;
                            mult*=10;
                        }else{
                            addition+=currentdig[l]%10*mult;
                            digcount++;
                            mult*=10;
                            addition+=currentdig[l]/10*mult;
                            digcount++;
                            mult*=10;
                        }
                        l++;
                    }
                    if(addition%16==0){
                        countt++;
                    }
                }
            }
        }
    }
    countt%=goog;
    res=(countt*fac[n-4])%goog;
    cout << res << endl;
    return 0;
}
