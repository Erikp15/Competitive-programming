#include <bits/stdc++.h>

using namespace std;

    vector<int> all_k_nodes;
    map<int, int> node_to_index;
    map<int, int>::iterator it;

int main(){
    long long p,m,k;
    cin>>p>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        node_to_index[a]++;
        node_to_index[b]++;
    }
    cin>>k;
    for(it=node_to_index.begin();it!=node_to_index.end();++it){
        if(it->second>=k){
            all_k_nodes.push_back(it->first);
        }
    }
    cout<<all_k_nodes.size()<<endl;
    for(int i=0;i<(int)all_k_nodes.size();i++){
        cout<<all_k_nodes[i]<<" ";
    }
    cout<<endl;
    return 0;
}
