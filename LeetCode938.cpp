class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root==NULL) return 0;
        int sum=0;
        if(root->val>=low && root->val<=high) sum+=root->val;
        sum += rangeSumBST(root->left,low,high);
        sum += rangeSumBST(root->right,low,high);
        return sum;
    }
};