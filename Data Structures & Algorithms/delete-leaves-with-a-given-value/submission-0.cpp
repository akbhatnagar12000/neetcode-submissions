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
    bool isLeaf(TreeNode* root){
        return (root->left==nullptr && root->right==nullptr);
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        while(true)
        {   bool removed = false;
            queue<TreeNode*>q;
            q.push(root);
            while(!q.empty()){
                auto x = q.front();
                q.pop();
                if(x->left){
                    if(x->left->val==target && isLeaf(x->left)){
                        TreeNode* temp = x->left;
                        delete(temp);
                        x->left=nullptr;
                        removed=true;
                    }
                    else{
                        q.push(x->left);
                    }
                }
                if(x->right){
                    if(x->right->val==target && isLeaf(x->right)){
                        TreeNode* temp = x->right;
                        delete(temp);
                        x->right=nullptr;
                        removed=true;
                    }
                    else{
                        q.push(x->right);
                    }
                }
            }
            if(!removed)
                break;
        }
        if(root && isLeaf(root) && root->val==target){
            delete(root);
            return nullptr;
        }
        else{
            return root;
        }
    }
};