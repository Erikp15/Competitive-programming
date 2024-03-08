#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=2e4+1,mod=1e9+7;

ll ans=0,k;
bool dp2[Size][Size],is_c[Size][Size];

bool check2(ll d1,ll d2){
    if(d1>10000 or d2>10000)
        cout<<"c"<<endl;
    if(is_c[d1+10000][d2+10000])
        return !dp2[d1+10000][d2+10000];
    is_c[d1+10000][d2+10000]=1;
    if(d1+d2==k)
        return 1;
    if(d1-d2==k)
        return 1;
    if(d1*d2==k)
        return 1;
    if(d2!=0)
        if(d1%d2==0)
            if(d1/d2==k)
                return 1;
    dp2[d1+10000][d2+10000]=1;
    return 0;
}

bool check3(ll d1,ll d2,ll d3){
    if(check2(d1,d2+d3))
        return 1;
    if(check2(d1,d2-d3))
        return 1;
    if(check2(d1,d2*d3))
        return 1;
    if(d3!=0)
        if(d2%d3==0)
            if(check2(d1,d2/d3))
                return 1;
    if(check2(d1+d2,d3))
        return 1;
    if(check2(d1-d2,d3))
        return 1;
    if(check2(d1-d2,d3))
        return 1;
    if(d2!=0)
        if(d1%d2==0)
            if(check2(d1/d2,d3))
                return 1;
    if(d3>=0 and d2>0)
        if(check2(d1,d2*10+d3))
            return 1;
    if(d2>=0 and d1>0)
        if(check2(d1*10+d2,d3))
            return 1;
    return 0;
}

bool check4(ll d1,ll d2,ll d3,ll d4){
    if(check3(d1,d2,d3+d4))
        return 1;
    if(check3(d1,d2,d3-d4))
        return 1;
    if(check3(d1,d2,d3*d4))
        return 1;
    if(d4!=0)
        if(d3%d4==0)
            if(check3(d1,d2,d3/d4))
                return 1;
    if(check3(d1,d2+d3,d4))
        return 1;
    if(check3(d1,d2-d3,d4))
        return 1;
    if(check3(d1,d2*d3,d4))
        return 1;
    if(d3!=0)
        if(d2%d3==0)
            if(check3(d1,d2/d3,d4))
                return 1;
    if(check3(d1+d2,d3,d4))
        return 1;
    if(check3(d1-d2,d3,d4))
        return 1;
    if(check3(d1*d2,d3,d4))
        return 1;
    if(d2!=0)
        if(d1%d2==0)
            if(check3(d1/d2,d3,d4))
                return 1;
    if(d4>=0 and d3>0)
        if(check3(d1,d2,d3*10+d4))
            return 1;
    if(d3>=0 and d3>0)
        if(check3(d1,d2*10+d3,d4))
            return 1;
    if(d2>=0 and d1>0)
        if(check3(d1*10+d2,d3,d4))
            return 1;
    return 0;
}
bool check5(ll d1,ll d2,ll d3,ll d4,ll d5){
    if(check4(d1,d2,d3,d4+d5))
        return 1;
    if(check4(d1,d2,d3,d4-d5))
        return 1;
    if(check4(d1,d2,d3,d4*d5))
        return 1;
    if(d5!=0)
        if(d4%d5==0)
            if(check4(d1,d2,d3,d4/d5))
                return 1;
    if(check4(d1,d2,d3+d4,d5))
        return 1;
    if(check4(d1,d2,d3-d4,d5))
        return 1;
    if(check4(d1,d2,d3*d4,d5))
        return 1;
    if(d4!=0)
        if(d3%d4==0)
            if(check4(d1,d2,d3/d4,d5))
                return 1;
    if(check4(d1,d2+d3,d4,d5))
        return 1;
    if(check4(d1,d2-d3,d4,d5))
        return 1;
    if(check4(d1,d2*d3,d4,d5))
        return 1;
    if(d3!=0)
        if(d2%d3==0)
            if(check4(d1,d2/d3,d4,d5))
                return 1;
    if(check4(d1+d2,d3,d4,d5))
        return 1;
    if(check4(d1-d2,d3,d4,d5))
        return 1;
    if(check4(d1*d2,d3,d4,d5))
        return 1;
    if(d2!=0)
        if(d1%d2==0)
            if(check4(d1/d2,d3,d4,d5))
                return 1;
    if(d5>=0 and d4>0)
        if(check4(d1,d2,d3,d4*10+d5))
            return 1;
    if(d4>=0 and d3>0)
        if(check4(d1,d2,d3*10+d4,d5))
            return 1;
    if(d3>=0 and d2>0)
        if(check4(d1,d2*10+d3,d4,d5))
            return 1;
    if(d2>=0 and d1>0)
        if(check4(d1*10+d2,d3,d4,d5))
            return 1;
    return 0;
}

bool check(ll n){
    vector<ll> digs;
    while(n>0){
        digs.push_back(n%10);
        n/=10;
    }
    if(digs.size()==1){
        if(digs[0]==k or -digs[0]==k)
            return 1;
    }
    if(digs.size()==2){
        if(check2(digs[1],digs[0]))
            return 1;
        if(check2(-digs[1],digs[0]))
            return 1;
        if(check2(digs[1],-digs[0]))
            return 1;
        if(check2(-digs[1],-digs[0]))
            return 1;
    }
    if(digs.size()==3){
        if(check3(digs[2],digs[1],digs[0]))
            return 1;
        if(check3(digs[2],digs[1],-digs[0]))
            return 1;
        if(check3(digs[2],-digs[1],digs[0]))
            return 1;
        if(check3(digs[2],-digs[1],-digs[0]))
            return 1;
        if(check3(-digs[2],digs[1],digs[0]))
            return 1;
        if(check3(-digs[2],digs[1],-digs[0]))
            return 1;
        if(check3(-digs[2],-digs[1],digs[0]))
            return 1;
        if(check3(-digs[2],-digs[1],-digs[0]))
            return 1;
    }
    if(digs.size()==4){
        if(check4(digs[3],digs[2],digs[1],digs[0]))
            return 1;
        if(check4(digs[3],digs[2],digs[1],-digs[0]))
            return 1;
        if(check4(digs[3],digs[2],-digs[1],digs[0]))
            return 1;
        if(check4(digs[3],digs[2],-digs[1],-digs[0]))
            return 1;
        if(check4(digs[3],-digs[2],digs[1],digs[0]))
            return 1;
        if(check4(digs[3],-digs[2],digs[1],-digs[0]))
            return 1;
        if(check4(digs[3],-digs[2],-digs[1],digs[0]))
            return 1;
        if(check4(digs[3],-digs[2],-digs[1],-digs[0]))
            return 1;
        if(check4(-digs[3],digs[2],digs[1],digs[0]))
            return 1;
        if(check4(-digs[3],digs[2],digs[1],-digs[0]))
            return 1;
        if(check4(-digs[3],digs[2],-digs[1],digs[0]))
            return 1;
        if(check4(-digs[3],digs[2],-digs[1],-digs[0]))
            return 1;
        if(check4(-digs[3],-digs[2],digs[1],digs[0]))
            return 1;
        if(check4(-digs[3],-digs[2],digs[1],-digs[0]))
            return 1;
        if(check4(-digs[3],-digs[2],-digs[1],digs[0]))
            return 1;
        if(check4(-digs[3],-digs[2],-digs[1],-digs[0]))
            return 1;
    }
    if(digs.size()==5){
        if(check5(digs[4],digs[3],digs[2],digs[1],digs[0]))
            return 1;
        if(check5(digs[4],digs[3],digs[2],digs[1],-digs[0]))
            return 1;
        if(check5(digs[4],digs[3],digs[2],-digs[1],digs[0]))
            return 1;
        if(check5(digs[4],digs[3],digs[2],-digs[1],-digs[0]))
            return 1;
        if(check5(digs[4],digs[3],-digs[2],digs[1],digs[0]))
            return 1;
        if(check5(digs[4],digs[3],-digs[2],digs[1],-digs[0]))
            return 1;
        if(check5(digs[4],digs[3],-digs[2],-digs[1],digs[0]))
            return 1;
        if(check5(digs[4],digs[3],-digs[2],-digs[1],-digs[0]))
            return 1;
        if(check5(digs[4],-digs[3],digs[2],digs[1],digs[0]))
            return 1;
        if(check5(digs[4],-digs[3],digs[2],digs[1],-digs[0]))
            return 1;
        if(check5(digs[4],-digs[3],digs[2],-digs[1],digs[0]))
            return 1;
        if(check5(digs[4],-digs[3],digs[2],-digs[1],-digs[0]))
            return 1;
        if(check5(digs[4],-digs[3],-digs[2],digs[1],digs[0]))
            return 1;
        if(check5(digs[4],-digs[3],-digs[2],digs[1],-digs[0]))
            return 1;
        if(check5(digs[4],-digs[3],-digs[2],-digs[1],digs[0]))
            return 1;
        if(check5(digs[4],-digs[3],-digs[2],-digs[1],-digs[0]))
            return 1;
        if(check5(-digs[4],digs[3],digs[2],digs[1],digs[0]))
            return 1;
        if(check5(-digs[4],digs[3],digs[2],digs[1],-digs[0]))
            return 1;
        if(check5(-digs[4],digs[3],digs[2],-digs[1],digs[0]))
            return 1;
        if(check5(-digs[4],digs[3],digs[2],-digs[1],-digs[0]))
            return 1;
        if(check5(-digs[4],digs[3],-digs[2],digs[1],digs[0]))
            return 1;
        if(check5(-digs[4],digs[3],-digs[2],digs[1],-digs[0]))
            return 1;
        if(check5(-digs[4],digs[3],-digs[2],-digs[1],digs[0]))
            return 1;
        if(check5(-digs[4],digs[3],-digs[2],-digs[1],-digs[0]))
            return 1;
        if(check5(-digs[4],-digs[3],digs[2],digs[1],digs[0]))
            return 1;
        if(check5(-digs[4],-digs[3],digs[2],digs[1],-digs[0]))
            return 1;
        if(check5(-digs[4],-digs[3],digs[2],-digs[1],digs[0]))
            return 1;
        if(check5(-digs[4],-digs[3],digs[2],-digs[1],-digs[0]))
            return 1;
        if(check5(-digs[4],-digs[3],-digs[2],digs[1],digs[0]))
            return 1;
        if(check5(-digs[4],-digs[3],-digs[2],digs[1],-digs[0]))
            return 1;
        if(check5(-digs[4],-digs[3],-digs[2],-digs[1],digs[0]))
            return 1;
        if(check5(-digs[4],-digs[3],-digs[2],-digs[1],-digs[0]))
            return 1;
    }
    return 0;
}


void solve(){
    ll n;
    cin>>n>>k;
    if(n==100000){
        n--;
        if(k==-100000 or k==-10000 or k==-1000 or k==-100 or k==-10 or k==-1 or k==0 or k==1 or k==10 or k==100 or k==1000 or k==10000 or k==100000)
            ans++;
    }
    for(ll i=0;i<=n;i++){
        if(check(i))
            ans++;
    }
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    while(t--){
        solve();
    }
    return 0;
}
