///Task: bestans
///Author: Vladimir Vladimirov
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int level[1000000], P, A, B, R;
int N;
queue <int> q;

void bfs(int n)
{
    q.push ( n%P );
    
    while ( !q.empty() )
    {
        int currentN = q.front();       q.pop();
        
        if (currentN == R && level[ currentN ]) break;
        
        if ( !level[ (currentN+A) %P ])
        {
            level[ (currentN+A) %P ] = level[currentN] + 1;
            q.push( (currentN+A) %P );
        }
        if ( !level[ (currentN+B) %P ])
        {
            level[ (currentN+B) %P ] = level[currentN] + 1;
            q.push( (currentN+B) %P );
        }
    }
    
}

int main()
{
    memset ( level, 0, sizeof(level) );         
    cin >> N >> P >> A >> B >> R;
    
    bfs( N );
    
    if (level[R] != 0) cout << level[R] << endl;
    else cout << -1 << endl;
    
    return 0;
}
