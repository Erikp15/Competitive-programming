#include <bits/stdc++.h>

#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize("Ofast")//Comment optimisations for interactive problems (use endl)
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

using namespace std;
typedef long long ll;

const ll Size=1e5+1;

string a,b;
vector<pair<ll,ll> > list_of_ans;
ll bucket[3][Size];
ll b_size[3];
bool primary_dump;
ll secondary_dump;
bool top[2],first[2];
bool truearr[3];
ll n,p;

void solve(){
    b_size[0]=b_size[1]=b_size[2]=0;
    ll ans=0;
    cin>>n>>p;
    cin>>a>>b;
    first[0]=a[0]-'0'-1;
    first[1]=b[0]-'0'-1;
    ll curr_count=1;
    for(ll i=1;i<a.size();i++){
        if(a[i]!=a[i-1]){
            bucket[0][b_size[0]]=curr_count;
            curr_count=1;
            b_size[0]++;
        }else{
            curr_count++;
        }
    }
    bucket[0][b_size[0]]=curr_count;
    curr_count=1;
    b_size[0]++;
    for(ll i=1;i<a.size();i++){
        if(b[i]!=b[i-1]){
            bucket[1][b_size[1]]=curr_count;
            curr_count=1;
            b_size[1]++;
        }else{
            curr_count++;
        }
    }
    bucket[1][b_size[1]]=curr_count;
    curr_count=1;
    b_size[1]++;
    if(b_size[0]==1 and b_size[1]==1){
        cout<<0<<endl;
        return;
    }
    if(b_size[1]==1){
        truearr[0]=!first[1];
        truearr[1]=first[1];
        truearr[2]=!first[1];
        primary_dump=0;
        secondary_dump=-1;
    }else if(b_size[0]==1){
        truearr[0]=first[0];
        truearr[1]=!first[0];
        truearr[2]=!first[0];
        primary_dump=1;
        secondary_dump=-1;
    }else{
        truearr[0]=first[0];
        truearr[1]=!first[0];
        truearr[2]=!first[0];
        primary_dump=0;
        secondary_dump=1;
    }
    top[0]=a[n-1]-'0'-1;
    top[1]=b[n-1]-'0'-1;
    if(secondary_dump!=-1){
        ll to_add=0;
        if(top[0]==truearr[2]){
            b_size[0]--;
            top[0]=!top[0];
            to_add+=bucket[0][b_size[0]];
            ans++;
            list_of_ans.push_back({1,3});
            bucket[0][b_size[0]]=0;

        }
        if(top[1]==truearr[2]){
            b_size[1]--;
            top[1]=!top[1];
            to_add+=bucket[1][b_size[1]];
            bucket[1][b_size[1]]=0;
            ans++;
            list_of_ans.push_back({2,3});
        }
        if(to_add!=0){
            bucket[2][b_size[2]]=to_add;
            b_size[2]++;
        }
    }
    while(b_size[primary_dump]!=0 and (b_size[primary_dump]!=1 or top[primary_dump]!=truearr[primary_dump])){
        if(top[primary_dump]==truearr[2]){
            b_size[primary_dump]--;
            bucket[2][b_size[2]]=bucket[primary_dump][b_size[primary_dump]];
            b_size[2]++;
            bucket[primary_dump][b_size[primary_dump]]=0;
            top[primary_dump]=!top[primary_dump];
            ans++;
            list_of_ans.push_back({primary_dump+1,3});
        }else{
            b_size[primary_dump]--;
            if(top[!primary_dump]==top[primary_dump]){
                bucket[!primary_dump][b_size[!primary_dump]]+=bucket[primary_dump][b_size[primary_dump]];
            }else{
                bucket[!primary_dump][b_size[!primary_dump]]=bucket[primary_dump][b_size[primary_dump]];
                b_size[!primary_dump]++;
            }
            bucket[primary_dump][b_size[primary_dump]]=0;
            top[primary_dump]=!top[primary_dump];
            ans++;
            list_of_ans.push_back({primary_dump+1,!primary_dump+1});
        }
    }
    if(secondary_dump!=-1){
        while(b_size[secondary_dump]!=0 and (b_size[secondary_dump]!=1 or top[secondary_dump]!=truearr[secondary_dump])){
            if(top[secondary_dump]==truearr[2]){
                b_size[secondary_dump]--;
                bucket[2][b_size[2]]=bucket[primary_dump][b_size[primary_dump]];
                b_size[2]++;
                bucket[secondary_dump][b_size[secondary_dump]]=0;
                top[secondary_dump]=!top[secondary_dump];
                ans++;
                list_of_ans.push_back({secondary_dump+1,3});
            }else{
                b_size[secondary_dump]--;
                if(top[secondary_dump]=top[!secondary_dump]){
                    bucket[!secondary_dump][b_size[!secondary_dump]]+=bucket[secondary_dump][b_size[secondary_dump]];
                }else{
                    bucket[!secondary_dump][b_size[!secondary_dump]]=bucket[secondary_dump][b_size[secondary_dump]];
                    b_size[!secondary_dump]++;
                }
                bucket[secondary_dump][b_size[secondary_dump]]=0;
                top[secondary_dump]=!top[secondary_dump];
                ans++;
                list_of_ans.push_back({secondary_dump+1,!secondary_dump+1});
            }
        }
    }
    if(truearr[2]==truearr[0] and b_size[2]!=0){
        ans++;
        list_of_ans.push_back({3,1});
    }else if(truearr[2]==truearr[1] and b_size[2]!=0){
        ans++;
        list_of_ans.push_back({3,2});
    }
    cout<<ans<<endl;
    if(p!=1){
        for(auto itrv:list_of_ans){
            cout<<itrv.first<<" "<<itrv.second<<endl;
        }
    }
    list_of_ans.clear();
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
1
4 3
1221
2211

1
6 3
222222
111112

1
4 3
1121
1222
*/
