#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

pair<ll,ll> last[26];
ll appear[26],target[26],pos[26];

void solve(){
    string a,order,ans;
    cin>>a;
    order="";
    ans="";
    for(ll i=0;i<26;i++){
        last[i].second=i;
        last[i].first=-1;
        appear[i]=0;
    }
    for(ll i=0;i<(ll)a.size();i++){
        last[a[i]-'a'].first=i;
        appear[a[i]-'a']++;
    }
    sort(last,last+26);
    for(ll i=0;i<26;i++){
        if(last[i].first!=-1){
            order+=last[i].second+'a';
            pos[last[i].second]=order.size();
        }
    }
    for(ll i=0;i<26;i++){
        ll index=last[i].second;
        if(last[i].first!=-1){
            if(appear[index]%pos[index]!=0){
                cout<<-1<<"\n";
                return;
            }
            target[index]=appear[index]/pos[index];
            appear[index]=0;
        }
    }
    for(ll i=0;i<(ll)a.size();i++){
        appear[a[i]-'a']++;
        ans+=a[i];
        bool found=true;
        for(ll j=0;j<26;j++){
            ll index=last[j].second;
            if(appear[index]!=target[index] and last[j].first!=-1){
                found=false;
                break;
            }
        }
        if(found){
            break;
        }
    }
    ll sum=0;
    ll j=0;
    for(ll i=0;i<(ll)order.size();i++){
        j=j+ans.size()-sum;
        sum+=target[order[i]-'a'];
        for(ll p1=0;j<ans.size()+ans.size()-sum;j++,p1++){
            while(true){
                ll is=false;
                for(ll k=0;k<=i;k++){
                    if(ans[p1]==order[k]){
                        is=true;
                    }
                }
                if(is){
                    p1++;
                }else{
                    break;
                }
            }
            if(a[j]!=ans[p1]){
                cout<<-1<<"\n";
                return;
            }
        }
    }
    cout<<ans<<" "<<order<<"\n";
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
