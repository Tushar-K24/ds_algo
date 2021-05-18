#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<algorithm>
#define int long long
#define endl "\n"
#define pb push_back
#define vec vector
using namespace std;

class Solution{
    public:
    void dfs(vec<vec<int>> &graph, stack<int> &sorted, vec<int> &visited, int n){
        visited[n]=1;
        for(int i:graph[n]){
            if(!visited[i]){
                dfs(graph,sorted,visited,i);
            }
        }
        sorted.push(n);
    }

    void topological_sort(vec<vec<int>> &graph, vec<int> &soln, int n){
        stack<int> sorted;
        vec<int> visited(n+1,0);
        for(int i=0;i<=n;i++){
            if(!visited[i]){
                dfs(graph, sorted, visited, i);
            }
        }
        while(!sorted.empty()){
            int x=sorted.top();
            soln.pb(x);
            sorted.pop();
        }
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
    vec<int> sorted;
    Solution.topological_sort(graph,sorted,n);
    for(int i=0;i<sorted.size();i++)
        cout<<sorted[i]<<" ";
    cout<<endl;
    return 0;
}