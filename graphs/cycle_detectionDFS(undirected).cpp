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
    bool check_dfs(vec<vec<int>> &graph, vec<int> &vis, int node, int par){
        vis[node]=1;
        for(int x: graph[node]){
            if(vis[x]){
                if(x!=par){
                    return true;
                }
            }
            else{
                if(check_dfs(graph,vis,x,node)){
                    return true;
                }
            }
        }
        return false;
    }
    bool check(vec<vec<int>> &graph, int n){
        vec<int> vis(n+1,0);
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                if(check_dfs(graph,vis,i,-1)){
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