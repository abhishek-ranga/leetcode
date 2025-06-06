class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL) return nullptr;
        if(root->val==val) return root;
        else if(root->val>val) return searchBST(root->left,val);
        else return searchBST(root->right,val);
    }
};