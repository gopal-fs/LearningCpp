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
    TreeNode *ans=nullptr;
    void find(TreeNode* root, int val){
        if(!root) return ;
        if(root->val==val && ans==nullptr) ans=root;

        if(val<root->val) find(root->left,val);
        else find(root->right,val);
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        find(root,val);
        return ans;
        
        
    }
};