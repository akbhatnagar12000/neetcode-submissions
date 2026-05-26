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
    void countPaths(TreeNode* root, int &ans, int maxtillnow){
        if(root==nullptr) return;
        if(maxtillnow<=root->val){
            ans++;
            maxtillnow=root->val;
        }
        countPaths(root->left,ans,maxtillnow);
        countPaths(root->right,ans,maxtillnow);
    }
    int goodNodes(TreeNode* root) {
        if(root==nullptr) return 1;
        int ans = 1;
        countPaths(root->left, ans, root->val);
        countPaths(root->right, ans, root->val);
        return ans;
    }
};
