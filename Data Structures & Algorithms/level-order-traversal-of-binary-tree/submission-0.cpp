/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(root == nullptr) return res;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            vector<int>sub_res;
            int sz = q.size();
            for(int i=0;i<sz;i++){
                auto x = q.front();
                q.pop();
                sub_res.push_back(x->val);
                if(x->left){
                    q.push(x->left);
                }
                if(x->right){
                    q.push(x->right);
                }
            }
            res.push_back(sub_res);
        }
        return res;
    }
};
