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
    int idx = 0;
    TreeNode* buildRec(vector<int>& preorder, unordered_map<int,int>&mp, int st, int en)
    {
        if(idx>=preorder.size() || st>en){
            return nullptr;
        }
        if(st==en){
            return new TreeNode(preorder[idx++]);
        }
        int i = idx;
        idx++;
        TreeNode* root = new TreeNode(preorder[i]);
        i = mp[preorder[i]];
        root->left = buildRec(preorder,mp,st,i-1);
        root->right = buildRec(preorder,mp,i+1,en);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0) return nullptr;
        unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        int n = preorder.size();
        return buildRec(preorder,mp,0,n-1);
    }
};
