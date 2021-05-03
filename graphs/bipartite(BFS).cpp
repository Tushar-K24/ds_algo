#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
#define int long long
#define endl "\n"
#define pb push_back
#define vec vector
using namespace std;

class solution{
    public:
    bool bipartite_bfs(vec<vec<int>> &graph, vec<int> &color, int node){
        color[node]=0;
        queue<int> bfs;
        bfs.push(node);
        while(!bfs.empty()){
            int curr=bfs.front();
            bfs.pop();
            for(int x: graph[curr]){
                if(color[x]==-1){
                    bfs.push(x);
                    color[x]=1-color[curr];
                }
                else if(color[x]==color[curr])
                    return false;
            }
        }
        return true;
    }

    bool check(vec<vec<int>> &graph, int n){
        vec<int> color(n+1,-1);
        for(int i=1;i<=n;i++){
            if(color[i]==-1){
                if(!bipartite_bfs(graph,color,i)){
                    return false;
                }
            }
        }
        return true;
    }
}solution;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,e;
    cin>>n>>e;
    vec<vec<int>> graph(n+1);
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    if(solution.check(graph,n))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}