class Solution {
public:
    void inorderTraversal(TreeNode *root,vector<int> &nums){
        if(!root) return;

        inorderTraversal(root->left,nums);
        nums.push_back(root->val);
        inorderTraversal(root->right,nums);
        
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> nums;
        inorderTraversal(root,nums);

        int i=0;
        int j=nums.size()-1;
        while(i<j){
            if(nums[i]+nums[j]<k) i++;
            else if(nums[i]+nums[j]>k) j--;
            else return true;
        }
        return false;
    }
};