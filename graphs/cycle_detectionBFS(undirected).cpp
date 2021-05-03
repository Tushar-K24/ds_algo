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
    bool cycle_bfs(vec<vec<int>> &graph, vec<int> &vis, int node){
        queue<pair<int,int>> bfs;
        bfs.push({node,-1});
        vis[node]=1;
        while(!bfs.empty()){
            int qnode=bfs.front().first;
            int qpar=bfs.front().second;
            bfs.pop();
            for(int x: graph[qnode]){
                if(vis[x]==1){
                    if(x!=qpar)
                        return true;
                }
                else{
                    vis[x]=1;
                    bfs.push({x,qnode});
                }
            }
        }
        return false;
    }
    bool check(vec<vec<int>> &graph, int n){
        vec<int> vis(n+1,0);
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                if(cycle_bfs(graph,vis,i)){
                    cout<<i<<endl;
                    return true;
                }
            }
        }
        return false;
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
    if(solution.check(graph,n)){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}