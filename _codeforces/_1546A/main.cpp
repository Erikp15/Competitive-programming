#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    const ll Size=101;

    void solve(){
        ll n;
        cin>>n;
        ll a[Size],b[Size],sum=0,m=0;
        vector<ll> lower,lower_i,great,great_i;
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        for(ll i=0;i<n;i++){
            cin>>b[i];
        }
        for(ll i=0;i<n;i++){
            if(b[i]-a[i]==0)continue;
            if(b[i]-a[i]>0){
                great.push_back(b[i]-a[i]);
                great_i.push_back(i);
                //cout<<great_i[great_i.size()-1]<<" g ";
                m+=b[i]-a[i];
            }else{
                lower.push_back(b[i]-a[i]);
                lower_i.push_back(i);
                //cout<<lower_i[lower_i.size()-1]<<" l ";
            }
            sum+=b[i]-a[i];
        }
        if(sum!=0){
            cout<<-1<<"\n";
            return;
        }
        cout<<m<<"\n";
        if(lower.empty() or great.empty()){
            return;
        }
        ll pl=0,pg=0;
        bool is_pl=false,is_pg=false;
        for(;!is_pl or !is_pg;){
            if(lower[pl]<0 and !is_pl){
                cout<<lower_i[pl]+1<<" ";
                lower[pl]++;
            }else{
                if(pl<lower.size()-1 and !is_pl){
                    pl++;
                    cout<<lower_i[pl]+1<<" ";
                    lower[pl]++;
                }else{
                    is_pl=true;
                }
            }
            if(great[pg]>0 and !is_pg){
                cout<<great_i[pg]+1<<"\n";
                great[pg]--;
            }else{
                if(pg<great.size()-1 and !is_pg){
                    pg++;
                    cout<<great_i[pg]+1<<"\n";
                    great[pg]--;
                }else{
                    is_pg=true;
                }
            }
        }
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
