#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=1e5+10,max_val=2e6+1,r=1e9+7;

ll unique_digsA=0,unique_digsB=0,w,k,n,m;
ll a[Size],b[Size],dig_ans[2][max_val],dig_count[2][max_val],p_pow[Size];
unordered_map<ll,ll> all_strings_a,all_strings_b;

void solve(){
    cin>>w>>k>>n;
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>m;
    for(ll i=0;i<m;i++){
        cin>>b[i];
    }
    if(k>n or k>m){
        cout<<0<<endl;
        return;
    }
    if(w==1){
        ll p=2000003;
        p_pow[0]=p;
        for(ll i=1;i<k;i++){
            p_pow[i]=(p_pow[i-1]*p)%r;
        }
        ll hash_a=0,hash_b=0,prev_a=-1,prev_b=-1;
        for(ll i=0;i<k;i++){
            hash_a=(hash_a+(p_pow[k-i-1]*a[i])%r)%r;
            if(a[i]<=a[i-1] and i){
                prev_a=i-1;
            }
        }
        for(ll i=0;i<k;i++){
            hash_b=(hash_b+(p_pow[k-i-1]*b[i])%r)%r;
            if(b[i]<=b[i-1] and i){
                prev_b=i-1;
            }
        }
        all_strings_a[hash_a]++;
        all_strings_b[hash_b]++;
        //acout<<hash_a<<" 1"<<endl;
        //cout<<hash_b<<" 2"<<endl;
        for(ll i=k;i<max(n,m);i++){
            hash_a=((hash_a+a[i]+r-((a[i-k]*p_pow[k-1])%r))%r*p)%r;
            hash_b=((hash_b+b[i]+r-((b[i-k]*p_pow[k-1])%r))%r*p)%r;
            if(a[i]<=a[i-1]){
                prev_a=i-1;
            }
            if(b[i]<=b[i-1]){
                prev_b=i-1;
            }
            if(i<n and (i-prev_a>=k or prev_a==-1)){
                all_strings_a[hash_a]++;
                //cout<<hash_a<<" 1"<<endl;
            }
            if(i<m and (i-prev_b>=k or prev_b==-1)){
                all_strings_b[hash_b]++;
                //cout<<hash_b<<" 2"<<endl;
            }
        }
        ll ans=0;
        for(auto itr:all_strings_a){
            ans+=itr.second*all_strings_b[itr.first];
        }
        cout<<ans<<endl;
    }
    if(w==2){
        for(ll i=0;i<k;i++){
            if(dig_count[0][a[i]]==0)
                unique_digsA++;
            if(dig_count[1][b[i]]==0)
                unique_digsB++;
            dig_count[0][a[i]]++;
            dig_count[1][b[i]]++;
        }
        if(unique_digsA==1)
            dig_ans[0][a[k-1]]++;
        if(unique_digsB==1)
            dig_ans[1][b[k-1]]++;
        for(ll i=k;i<n;i++){
            if(dig_count[0][a[i]]==0)
                unique_digsA++;
            dig_count[0][a[i]]++;
            dig_count[0][a[i-k]]--;
            if(dig_count[0][a[i-k]]==0)
                unique_digsA--;
            if(unique_digsA==1)
                dig_ans[0][a[i-1]]++;
        }
        for(ll i=k;i<m;i++){
            if(dig_count[1][b[i]]==0)
                unique_digsB++;
            dig_count[1][b[i]]++;
            dig_count[1][b[i-k]]--;
            if(dig_count[1][b[i-k]]==0)
                unique_digsB--;
            if(unique_digsB==1)
                dig_ans[1][b[i-1]]++;
        }
        ll ans=0;
        for(ll i=0;i<max_val;i++){
            ans+=dig_ans[0][i]*dig_ans[1][i];
        }
        cout<<ans<<endl;
        return;
    }
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
/*
2 3
11
3 4 4 4 4 5 6 6 6 6 7
16
3 6 6 6 4 4 4 5 6 6 6 7 7 6 6 6
8

1 2
6
2 1 3 4 3 6
6
3 6 1 3 6 7
3

1 2
4
1 2 3 4
5
2 3 4 3 4
3

1 2
4
4 5 3 1
3
1 4 5
1
*/
