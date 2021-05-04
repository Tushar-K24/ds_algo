//https://leetcode.com/problems/clone-graph/
class Solution {
public:
    vector<Node*> visited;
    Solution(): visited(101,NULL){}
    Node* cloneGraph(Node* node) {
        if(node==NULL)
            return NULL;
        if(visited[node->val]){
            return visited[node->val];
        }
        Node* duplicate_node=new Node;
        duplicate_node->val=node->val;
        visited[node->val]=duplicate_node;
        for(Node* x: node->neighbors){
            (duplicate_node->neighbors).push_back(cloneGraph(x));
        }
        return duplicate_node;
    }
};