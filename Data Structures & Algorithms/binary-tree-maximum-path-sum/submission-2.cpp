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
    int ans = 0;
    int solveRec(TreeNode* root){
        if(!root) return 0;
        int lmax = max(solveRec(root->left),0);
        int rmax = max(solveRec(root->right),0);
        ans = max(ans,root->val+lmax+rmax);
        return root->val+max(lmax,rmax);
    }
    int maxPathSum(TreeNode* root) {
        if(root==nullptr) return 0;
        ans = root->val;
        solveRec(root);
        return ans;
    }
};
