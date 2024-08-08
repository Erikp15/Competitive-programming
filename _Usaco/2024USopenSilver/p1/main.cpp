#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll Size=3e5+1;

ll t[Size];
map<ll,pair<ll,set<ll> > > time2state;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,k;
    cin>>n>>k;
    for(ll i=0;i<n;i++){
        cin>>t[i];
    }
    for(ll i=0;i<k;i++){
        if(time2state.find(t[i])==time2state.end()){
            set<ll> tmp;
            tmp.insert(i);
            time2state[t[i]]={1,tmp};
        }else{
            pair<ll,set<ll> > oldstate=time2state[t[i]];
            set<ll> newstate;
            newstate.insert(i);
            oldstate.second.insert(newstate.begin(),newstate.end());
            oldstate.first++;
            time2state[t[i]]=oldstate;
        }
    }
    /*
    for(auto itrv:time2state){
        cout<<itrv.first<<" "<<itrv.second.first<<" ";
        for(auto itrv2:itrv.second.second){
            cout<<itrv2<<" ";
        }
        cout<<endl;
    }
    */
    ll next_cow=k;
    for(; next_cow<n; time2state.erase(time2state.begin())){
        pair<ll,pair<ll,set<ll> > > curr_state=*time2state.begin();
        while(curr_state.second.first>0){
            if(time2state.find(curr_state.first+t[next_cow])==time2state.end()){
                time2state[curr_state.first+t[next_cow]]={1,curr_state.second.second};
            }else{
                pair<ll,set<ll> > old_state=time2state[curr_state.first+t[next_cow]];
                old_state.second.insert(curr_state.second.second.begin(),curr_state.second.second.end());
                old_state.first++;
                time2state[curr_state.first+t[next_cow]]=old_state;
            }
            curr_state.second.first--;
            next_cow++;
        }
    }
    cout<<(*time2state.begin()).first<<endl;
    string ans="";
    ll prev=0;
    for(auto itrv:(*time2state.begin()).second.second){
        for(ll i=prev;i<itrv;i++){
            ans+="0";
        }
        prev=itrv+1;
        ans+="1";
    }
    for(ll i=prev;i<k;i++){
        ans+="0";
    }
    cout<<ans<<endl;
    return 0;
}
/*
6 3
3 1 4159 2 6 5

6 3
1 1 4159 2 6 5
*/
