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
    void topological_sort(vec<vec<int>> &graph, vec<int> &sorted, int n){
        vec<int> indegree(n,0);
        queue<int> q;
        for(int i=0;i<n;i++){
            for(int it:graph[i]){
                indegree[it]++;
            }
        }
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int count=0;
        while(!q.empty()){
            int top=q.front();
            q.pop();
            sorted.pb(top);          
            for(int i:graph[top]){
                indegree[i]--;
                if(indegree[i]==0){
                    q.push(i);
                }
            }
        }
    }
}Solution;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,e;
    cin>>n>>e;
    vec<vec<int>> graph(n);
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        graph[u].pb(v);
    }    
    vec<int> sorted;
    Solution.topological_sort(graph,sorted,n);
    for(int i:sorted)
        cout<<sorted[i]<<" ";
    cout<<endl;
    return 0;
}