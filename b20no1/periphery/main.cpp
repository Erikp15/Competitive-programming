#include <bits/stdc++.h>

using namespace std;

struct ipair{
    int weight, nodeid;
};
bool operator<(const ipair& a, const ipair& b) {
    // NOTE that this is a reverse operator to get min heap. Need to be careful with < or > every time for this
  return a.weight > b.weight;
}

priority_queue<ipair,vector<ipair>> unvisited;
long long bestdist[100001];
vector<int> alledges[100001],kperi;

void dijkstra(ipair startnode){
    bestdist[startnode.nodeid]=0;
    unvisited.push(startnode);
    while(!unvisited.empty()){
        ipair currentnode=unvisited.top();
        unvisited.pop();
        for(int i=0;i<alledges[currentnode.nodeid].size();i++){
            if(bestdist[currentnode.nodeid]+1<bestdist[alledges[currentnode.nodeid][i]]){
                ipair toadd;
                toadd.weight=bestdist[currentnode.nodeid]+1;
                toadd.nodeid=alledges[currentnode.nodeid][i];
                bestdist[alledges[currentnode.nodeid][i]]=bestdist[currentnode.nodeid]+1;
                unvisited.push(toadd);
            }
        }
    }
}

int main(){
    long long n,m,c,k,p=0;
    cin>>n>>m>>c>>k;
    for(int i=1;i<=n;i++){
        ipair toadd;
        toadd.weight=1000000;
        toadd.nodeid=i;
        bestdist[i]=1000000;
        unvisited.push(toadd);
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        alledges[a].push_back(b);
        alledges[b].push_back(a);
    }
    ipair temp;
    temp.nodeid=c;
    dijkstra(temp);
    for(int i=1;i<=n;i++){
        if(bestdist[i]>k){
            kperi.push_back(i);
            p++;
        }
    }
    cout << p << endl;
    for(int i=0;i<kperi.size();i++){
        cout<<kperi[i]<<endl;
    }
    return 0;

}
