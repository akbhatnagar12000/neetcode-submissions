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
    int ans = -1;
    void inorder(TreeNode* root, int &counter){
        if(root==nullptr) return;
        inorder(root->left,counter);
        counter--;
        if(counter==0){
            ans=root->val;
        }
        inorder(root->right,counter);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>in;
        int counter=k;
        inorder(root,counter);
        return ans;
    }
};
