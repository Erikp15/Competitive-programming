#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=4e5+2;

void solve(){
    ll k;
    string a,ans,finding;
    finding+='6';
    for(ll i=0;i<8;i++)finding+='4';
    set<ll> digs;
    ll left[10];
    for(ll i=0;i<10;i++)left[i]=1e18;
    cin>>a>>k;
    ll large=a[0]-'0';
    for(ll i=0,used=0;i<(ll)a.size();i++){
        bool found=false;
        for(auto itr:digs){
            if(a[i]-'0'==itr){
                ans+=itr+'0';
                found=true;
                break;
            }
        }
        if(found)continue;
        if(used<k){
            large=max(large,ll(a[i]-'0'));
            left[a[i]-'0']=i;
            digs.insert(a[i]-'0');
            used++;
            ans+=a[i];
        }else{
            if(a[i]<large+'0'){
                ans+=*digs.lower_bound(a[i]-'0')+'0';
                while(ans.size()<a.size()){
                    ans+=*digs.begin()+'0';
                }
                cout<<ans<<"\n";
                return;
            }else{
                ll j=i-1;
                for(;digs.upper_bound(ans[j]-'0')==digs.end();j--){
                    if(left[ans[j]-'0']==j){
                        digs.erase(ans[j]-'0');
                        digs.insert(ans[j]-'0'+1);
                        ans[j]++;
                        for(ll k=j+1;k<(ll)ans.size();k++){
                            ans[k]=*digs.begin()+'0';
                        }
                        while(ans.size()<a.size()){
                            ans+=*digs.begin()+'0';
                        }
                        cout<<ans<<"\n";
                        return;
                    }
                }
                if(left[ans[j]-'0']==j){
                    if(*digs.upper_bound(ans[j]-'0')!=ans[j]-'0'+1){
                        digs.erase(ans[j]-'0');
                        digs.insert(ans[j]-'0'+1);
                        ans[j]++;
                        for(ll k=j+1;k<(ll)ans.size();k++){
                            ans[k]=*digs.begin()+'0';
                        }
                        while(ans.size()<a.size()){
                            ans+=*digs.begin()+'0';
                        }
                        cout<<ans<<"\n";
                        return;
                    }else{
                        digs.erase(ans[j]-'0');
                        ans[j]++;
                        for(ll k=j+1;k<(ll)ans.size();k++){
                            ans[k]='0';
                        }
                        while(ans.size()<a.size()){
                            ans+='0';
                        }
                        cout<<ans<<"\n";
                        return;
                    }
                }else{
                    ans[j]=*digs.upper_bound(ans[j]-'0')+'0';
                    for(ll k=j+1;k<(ll)ans.size();k++){
                        ans[k]=*digs.begin()+'0';
                    }
                    while(ans.size()<a.size()){
                        ans+=*digs.begin()+'0';
                    }
                    cout<<ans<<"\n";
                    return;
                }
            }
        }
    }
    cout<<ans<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
/*
111674811
646490893
633627900
*/
