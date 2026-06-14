/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        unordered_map<Node*, Node*>mp;
        unordered_map<Node*,bool>vis;
        queue<Node*>q;
        q.push(node);
        vis[node] = true;
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            mp[x] = new Node(x->val);
            for(auto c:x->neighbors){
                if(vis.find(c)==vis.end()){
                    q.push(c);
                    vis[c]=true;
                }
            }
        }  
        vis.clear();
        q.push(node);
        vis[node] = true;
        while(!q.empty()){
            auto x=q.front();
            q.pop();
            for(auto c:x->neighbors){
                mp[x]->neighbors.push_back(mp[c]);
                if(vis.find(c)==vis.end()){
                    q.push(c);
                    vis[c]=true;
                }
            }
        }
        return mp[node];
    }
};
