#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=2e3+3,mod=1e9+7;

char ans[Size];

void mult(ll n,ll k){
    char a[3][Size];
    for(ll i=0;i<3;i++){
        for(ll j=0;j<Size;j++){
            a[i][j]=0;
        }
    }
    ll j=n,c=0;
    for(;j>0;c++){
        ll num=j%10,carry=0,i=0;
        for(ll f=0;f<c;f++)a[c][f]='0';
        for(;i<k;i++){
            if(ans[i]=='0'-1)break;
            a[c][i+c]=((ans[i]-'0')*num+carry)%10+'0';
            carry=((ans[i]-'0')*num+carry)/10;
        }
        while(i<k and carry>0){
            a[c][i+c]=carry%10+'0';
            carry=carry/10;
        }
        j/=10;
    }
    for(ll i=0;i<=c;i++){
        ll carry=0;
        for(ll f=0;f<k;f++){
            if(a[i][f]==0)break;
            if(ans[i]=='0'-1){
                ans[f]=(a[i][f]-'0'+carry)%10+'0';
                carry=(ans[f]+a[i][f]-2*'0'+carry)/10;
            }else{
                if(i!=0){
                    ans[f]=(ans[f]+a[i][f]-2*'0'+carry)%10+'0';
                    carry=(ans[f]+a[i][f]-2*'0'+carry)/10;
                }else{
                    ans[f]=(a[i][f]-'0'+carry)%10+'0';
                    carry=(a[i][f]-'0'+carry)/10;
                }
            }
        }
    }
}

void solve(ll a,ll b,ll k){
    ll j=a,i=0;
    for(;j>0;i++){
        ans[i]=(j%10)+'0';
        j/=10;
    }
    for(;j<k;j++){
        ans[i]='0'-1;
    }
    ans[i]='0'-1;
    for(i=0;i<b;i++){
        mult(a,k);
    }
    cout<<ans[k]<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    cin>>t;
    while(t--){
        ll a,b,k;
        cin>>a>>b>>k;
        solve(a,b,k);
    }
    return 0;
}
/*
1
4 7 2
9
*/
