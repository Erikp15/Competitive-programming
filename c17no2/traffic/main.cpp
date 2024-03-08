#include <iostream>
#include <string>
#include <vector>

std::vector<int> neighbors[641][641],values[641][641];
int n,m,shortestpath[641][641];
bool ispassed[641][641]
std::string grid[641];

void dijkstra(int start){
    smallest[start/m][start%m]=0;
    while(ispassed[n-1][m-1]){
        int smallest=10000,smallestindex=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(smallest>shortestpath[i][j]){
                    smallest=shortestpath[i][j];
                    smallestindex=i*m+j;

                }
            }
        }
        ispassed[smallestindex/m][smallestindex%m]=true;
        for(int i=0;i<neighbors[smallestindex/m][smallestindex%m].size();i++){
            if(smallestindex%m==0 or smallestindex%m==m-1 or smallestindex%n==0 or smallestindex%n==n-1){
                
            }
            if(shortestpath[neighbors[smallestindex/m][smallestindex%m][i]]>shortestpath[smallestindex/m][smallestindex%m]+values[neighbors[smallestindex/m][smallestindex%m][i]] and ispassed[neighbors[smallestindex/m][smallestindex%m][i]]==false){
                shortestpath[neighbors[smallestindex/m][smallestindex%m][i]]=shortestpath[smallestindex/m][smallestindex%m]+values[neighbors[smallestindex/m][smallestindex%m][i]];
            }
        }
    }
}

int main(){
    int start;
    std::cin>>n>>m;
    for(int i=0;i<n;i++){
        std::cin>>grid[i];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            shortestpath[i][j]=-1;
            if(grid[i][j]=='#'){start=i*m+j;}
            if(grid[i][j+1]!='*' or j<m-1){
                neighbors[i*m+j].push_back(i*m+j+1);
                values[i*m+j].push_back(grid[i][j+1]-'A'+1);
            }
            if(grid[i][j-1]!='*' or j!=0){
                neighbors[i*m+j].push_back(i*m+j-1);
                values[i*m+j].push_back(grid[i][j-1]-'A'+1);
            }
            if(grid[i+1][j]!='*' or i<n-1){
                neighbors[i*m+j].push_back((i+1)*m+j);
                values[i*m+j].push_back(grid[i+1][j]-'A'+1);
            }
            if(i!=0){
                if(grid[i-1][j]!='*'){
                    neighbors[i*m+j].push_back((i-1)*m+j);
                    values[i*m+j].push_back(grid[i-1][j]-'A'+1);
                }
            }
        }
    }
    dijkstra(start);
    return 0;
}


/*
    for(int i=0;i<n*m;i++){
        std::cout<<i<<":";
        for(int j=0;j<neighbors[i].size();j++){
            std::cout<<values[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
*/
/*
8 12
NY****AZ****
*SH*D**CHMW*
*CJ**G**LZO*
*JMS****NGG*
*JKPKN#YORC*
************
KJWWGDPLQMXL
TGLAKBQCRQSD
*/
