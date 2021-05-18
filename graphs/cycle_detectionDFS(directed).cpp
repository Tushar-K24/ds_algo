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

class Solution{
    public:
    bool check_dfs(vec<vec<int>> &graph, vec<bool> &visited, vec<bool> &visitedDfs, int n){
        visited[n]=true;
        visitedDfs[n]=true;
        for(int i:graph[n]){
            if(visitedDfs[i]&&visited[i]){
                return true;
            }
            else if(!visited[i]){
                if(check_dfs(graph,visited,visitedDfs,i)) return true;
            }
        }
        visitedDfs[n]=false;
        return false;
    }

    bool cycle_check(vec<vec<int>> &graph, int n){
        vec<bool> visited(n+1,false);
        vec<bool> visitedDfs(n+1,false);
        for(int i=1;i<=n;i++){
            if(!visited[i]){
                if(check_dfs(graph, visited, visitedDfs, i)){
                    // cout<<i<<endl;
                    return true;
                }
            }
        }
        return false;
    }
}Solution;

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
    }    
    if(Solution.cycle_check(graph,n)){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}