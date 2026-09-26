class Solution {
public:
    TreeNode *makeBST(vector<int> &nums,int low,int high){
        if(low>high) return nullptr;

        int mid=(low)+(high-low)/2;

        TreeNode *newRoot=new TreeNode(nums[mid]);
        newRoot->left=makeBST(nums,low,mid-1);
        newRoot->right=makeBST(nums,mid+1,high);
        return newRoot;

    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return makeBST(nums,0,nums.size()-1);
        


    }
};