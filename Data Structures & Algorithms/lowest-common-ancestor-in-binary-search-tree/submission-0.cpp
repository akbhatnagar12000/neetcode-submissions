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
    TreeNode* solveRec(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==nullptr) return nullptr;
        if(root==p || root==q) return root;
        TreeNode* lc = solveRec(root->left,p,q);
        TreeNode* rc = solveRec(root->right,p,q);
        if(lc && rc){
            return root;
        }
        return lc?lc:rc;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solveRec(root,p,q);
    }
};
