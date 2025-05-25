class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        else return 1 + max(maxDepth(root->left),maxDepth(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        int LstHeight = maxDepth(root->left);
        int RstHeight = maxDepth(root->right);
        if(abs(LstHeight-RstHeight)>1) return false;
        else return isBalanced(root->left) && isBalanced(root->right); 
    }
};