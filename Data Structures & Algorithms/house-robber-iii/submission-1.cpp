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
    unordered_map<TreeNode*,int>mp;
    int rob(TreeNode* root) {
        if(root==nullptr) return mp[root]=0;
        if(mp.find(root)!=mp.end())
            return mp[root];
        int data = root->val;
        if(root->left){
            data+=rob(root->left->left)+rob(root->left->right);
        }
        if(root->right){
            data+=rob(root->right->right)+rob(root->right->left);
        }
        return mp[root]=max(data,rob(root->left)+rob(root->right));
    }
};